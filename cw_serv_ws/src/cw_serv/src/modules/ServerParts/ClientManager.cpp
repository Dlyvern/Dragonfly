#include "modules/ServerParts/ClientManager.hpp"

ClientManager::ClientManager(QWidget *parent) : QWidget(parent)
{

}

void ClientManager::MessageFromClient(const QJsonObject &message)
{
    auto* client(qobject_cast<TCPClient*>(sender()));

    if (!client) return;

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

void ClientManager::MessageForClient(const QJsonObject &message,  int idOfClient)
{
    auto client = m_TCPClients.find(idOfClient);
    if(client == m_TCPClients.end())
    {
        qDebug() << "New message for unknown client";
        return;
    }
    Log("New message for client with id " + std::to_string(idOfClient), 0, client->second.get());
    client->second->SendMessageToClient(message);
}

ClientManager::~ClientManager() = default;