#include "modules/TCPServer.hpp"

TCPServer::TCPServer(const std::string &name, QObject *parent) : QObject(parent), Module(name)
{
    this->declare_parameter("server/port_tcp", 8080);
    this->declare_parameter("server/ip", "127.0.0.1");

    m_Server = new QTcpServer(this);
    m_RunTimer = new QTimer();
    m_ClientManager = new ClientManager(this);

    connect(m_Server, &QTcpServer::newConnection, this, &TCPServer::NewConnection);

    connect(m_RunTimer, &QTimer::timeout, this, &TCPServer::Run);
}

void TCPServer::Start()
{
    m_Port = this->GetParameter("server/port_tcp").as_int();
    QString ip_string = QString::fromStdString(this->GetParameter("server/ip").as_string());
    m_Ip.setAddress(ip_string);

    if (!m_Server->listen(m_Ip, m_Port))
    {
        Log("Failed to start tcp/ip server: " + m_Server->errorString().toStdString(), ERROR_LEVEL_LOG);
        return;
    }

    Log("TCP/IP server started. Listening on " + std::to_string(m_Port) + " port, ip address: " + m_Ip.toString().toStdString(), INFO_LEVEL_LOG);

    SetRunInterval(std::chrono::milliseconds(100));

    m_RunTimer->setInterval(GetRunInterval());

    m_RunTimer->start();

    SetRunning(true);
}

void TCPServer::Run()
{
    ActivitySensor();
}

void TCPServer::NewConnection()
{
    while(m_Server->hasPendingConnections())
    {
        Log("Got a new client", INFO_LEVEL_LOG);

        QTcpSocket *client_socket = m_Server->nextPendingConnection();

        std::shared_ptr<TCPClient>tcp_client = std::make_shared<TCPClient>(client_socket, m_IdOfClient);

        tcp_client->Start();

        connect(tcp_client.get(), &TCPClient::LogClient, this, &TCPServer::LogMessageFromClient);

        m_ClientManager->AddNewClient(std::move(tcp_client));

        m_IdOfClient++;
    }
}

void TCPServer::LogMessageFromClient(const std::string &message, int levelLog)
{
    Log(message, levelLog);
}

TCPServer::~TCPServer() = default;