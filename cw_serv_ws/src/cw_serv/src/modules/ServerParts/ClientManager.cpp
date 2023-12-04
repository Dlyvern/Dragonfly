#include "modules/ServerParts/ClientManager.hpp"

ClientManager::ClientManager(QObject *parent) : QObject(parent){}

void ClientManager::Log(const std::string &message, int logLevel, TCPClient* tcpClient) const
{
    tcpClient->LogClient(message, logLevel);
}

void ClientManager::AddNewClient(std::shared_ptr<TCPClient> &&tcpClient)
{
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

ClientManager::~ClientManager() = default;