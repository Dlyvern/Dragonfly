#include "modules/ServerParts/TCPClient.hpp"
#include "cw_structs/Command.hpp"

TCPClient::TCPClient(QTcpSocket *clientSocket, int id, QObject*parent)
: QObject(parent), m_Socket(clientSocket), m_Id{id}
{
    m_PacketParser = new PacketParser;

    connect(m_PacketParser, &PacketParser::NewPacket, this, &TCPClient::ParsedNewPacket);

    connect(m_Socket, &QTcpSocket::readyRead, this, &TCPClient::ReadMessage);

    m_ActionClient = std::make_shared<ActionClient>();
    m_ActionClientTimer = new QTimer;
    m_ActionClientTimer->setInterval(100);
    connect(m_ActionClientTimer, &QTimer::timeout, [this]{spin_some(m_ActionClient);});
}

void TCPClient::Log(const std::string &message, int levelLog)
{
    std::string message_for_server = "Client[" + GetName().toStdString() + "]:" + message;
    emit LogClient(message_for_server, levelLog);
}

void TCPClient::Start()
{
    m_ActionClient->Start(std::bind(&TCPClient::ActionDoneCallback, this, std::placeholders::_1, std::placeholders::_2));

    m_ActionClientTimer->start();
}

void TCPClient::ActionDoneCallback(const std::string &resultArgs, bool result)
{
    QJsonObject message_for_client;

    message_for_client["type"] = "result";
    message_for_client["res"] = result;
    message_for_client["res_arg"] =  QString{resultArgs.c_str()};

    SendMessageToClient(message_for_client);
}

void TCPClient::ReadMessage()
{
    if(m_Socket->bytesAvailable())
    {
        auto data_from_socket = m_Socket->readAll();
        m_PacketParser->Start(data_from_socket);
    }
}

void TCPClient::Disconnect()
{
    m_Socket->disconnect();
    m_Socket->close();
}

const int &TCPClient::GetLevel() const
{
    return m_Level;
}

const QString &TCPClient::GetName() const
{
    return m_Name;
}

const int &TCPClient::GetId() const
{
    return m_Id;
}

void TCPClient::SendMessageToClient(const QJsonObject &message)
{
    auto msg = message;
    Packet packet(0xAA55, 0x01, 0x1234, 0, std::move(msg), 0xFFFF);

    QByteArray container = packet.Pack();

    m_Socket->write(container);
}

void TCPClient::ParsedNewPacket(Packet *packet)
{
    const QJsonObject &data = packet->GetData();

    QJsonObject message_for_client;

    if(data["type"] == "connect")
    {
        QString message = data["msg"].toString();

        m_Name = data["name"].toString();
        m_Level = data["level"].toInt();

        m_IsAlive = true;

        message_for_client["type"] = "message";
        message_for_client["msg"] = QString("You were connected with the name " + m_Name + " and with the " + QString(std::to_string(m_Level).c_str()) + " level of access");
        SendMessageToClient(message_for_client);
        //Send ping to server
    }

    else if(data["type"] == "get_op" && m_Level >= 2)
    {
        m_Operator = true;
    }

    else if(data["type"] == "cmd")
    {
        if(data["cmd"].toString() == "disconnect")
        {
            Log("Disconnecting client", 0);
            Disconnect();
            return;
        }

        else if(m_Operator)
        {
            Command* command = Command::FromCommandString(data["cmd"].toString().toStdString());

            if(command == nullptr) return;

            std::string arguments;
            std::string targets;
            std::string operation = command->GetOperation();

            const std::vector<std::string>arguments_container = command->GetArguments();
            const std::vector<std::string>targets_container = command->GetTarget();

            for(size_t index = 0; index < arguments_container.size(); ++index)
            {
                if(index != arguments_container.size() - 1)
                {
                    arguments += arguments_container.at(index) + ", ";
                    continue;
                }
                arguments += arguments_container.at(index);
            }

            for(const auto& target : targets_container)
                targets += target + ", ";

            targets.erase(targets.size() - 2);

            if(targets_container.size() > 1)
                targets.pop_back();

            std::string message_log = "\n-----------Message begin---------------\n";
            message_log += "Target: " + targets + "\n";
            message_log += "Operation: " + operation + "\n";
            message_log += "Arguments: " + arguments + "\n";
            message_log += "-----------Message end------------------";

            Log("Received new message from operator: "+ message_log, 0);

            QJsonObject new_command_data;

            new_command_data["type"] = "new_cmd";
            new_command_data["cmd"] = data["cmd"].toString();

            m_ActionClient->NewAction(*command);
        }
    }

    else
    {
        qDebug() << "WEIRD DATA";
    }
}

TCPClient::~TCPClient() = default;