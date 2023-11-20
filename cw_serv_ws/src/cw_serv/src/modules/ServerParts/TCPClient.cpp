#include "modules/ServerParts/TCPClient.hpp"

TCPClient::TCPClient(QTcpSocket *clientSocket, int id, QObject*parent)
: QObject(parent), m_Socket(clientSocket), m_Id{id}
{
    connect(m_Socket, &QTcpSocket::readyRead, this, &TCPClient::GotMessage);
}

void TCPClient::Log(const std::string &message, int levelLog)
{
    std::string message_for_server = "Client[" + GetName() + "]:" + message;
    emit LogClient(message_for_server, levelLog);
}

void TCPClient::Start()
{

}

void TCPClient::GotMessage()
{
    QByteArray dataForInitialization = m_Socket->readAll();

    Packet packet;

    if(!packet.Unpack(dataForInitialization))
    {
        Log("Got a broken message", 2); //ERROR LEVEL LOG
    }

    const QJsonObject &data = packet.GetData();

    if(data["type"] == "connect")
    {
        Log("Receiving init message with name and level", 0);

        QString message = data["msg"].toString();

        m_Name = data["name"].toString().toStdString();
        m_Level = data["level"].toInt();

        if((m_TCPOnly = data["tcp"].toBool()))
            Log("CONNECTED IN TCP_ONLY MODE", 0);

        Log("Connected with level " + std::to_string(m_Level), 0);
        m_IsAlive = true;
        //Send ping to server
    }

    else
        emit SendMessageToServer(data);
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

const std::string &TCPClient::GetName() const
{
    return m_Name;
}

const int &TCPClient::GetId() const
{
    return m_Id;
}

TCPClient::~TCPClient() = default;
