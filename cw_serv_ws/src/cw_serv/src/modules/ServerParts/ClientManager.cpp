#include "modules/ServerParts/ClientManager.hpp"

ClientManager::ClientManager(QWidget *parent) : QWidget(parent)
{

}

void ClientManager::MessageFromClient(const QJsonObject &message)
{
    TCPClient* client(qobject_cast<TCPClient*>(sender()));

    if (!client) return;

    QString type = message["type"].toString();

    if(type == "cmd")
    {
        if(message["cmd"].toString() == "disconnect")
        {
            DisconnectClient(client);
            return;
        }

        else if(emit IsOperator(client))
        {
            Command* command = Command::FromCommandString(message["cmd"].toString().toStdString());

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

            Log("Received new message from operator: "+ message_log, 0, client);

            if(targets_container[0] == "server")
            {
                return;
            }

            emit NewAction(client->GetId(), command);
        }
    }

    else if(type == "get_op")
    {
        emit NewOperator(client);
        return;
    }
}

void ClientManager::Log(const std::string &message, int logLevel, TCPClient* tcpClient) const
{
    tcpClient->LogClient(message, logLevel);
}

void ClientManager::AddNewClient(std::shared_ptr<TCPClient> &&tcpClient)
{
    connect(tcpClient.get(), &TCPClient::SendMessageToServer, this, &ClientManager::MessageFromClient);

    m_TCPClients[tcpClient->GetId()] = tcpClient;
}

bool ClientManager::DisconnectClient(TCPClient* tcpClient)
{
    for(auto client = m_TCPClients.begin(); client != m_TCPClients.end(); ++client)
    {
        if(client->second.get() == tcpClient)
        {
            tcpClient->Disconnect();
            m_TCPClients.erase(client);
            return true;
        }
    }

    return false;
}

void ClientManager::MessageForClient(int clientId, const QJsonObject &message)
{
    auto client = m_TCPClients.find(clientId);
    if(client == m_TCPClients.end())
    {
        qDebug() << "New message for unknown client";
        return;
    }
    Log("New message for client with id " + std::to_string(clientId), 0, client->second.get());
    client->second->SendMessageToClient(message);
}

ClientManager::~ClientManager() = default;