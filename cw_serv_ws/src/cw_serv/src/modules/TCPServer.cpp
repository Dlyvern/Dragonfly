#include "modules/TCPServer.hpp"

TCPServer::TCPServer(const std::string &name, QWidget *parent) : Module(name, parent)
{
    this->declare_parameter("server/port_tcp", 8080);
    this->declare_parameter("server/ip", "127.0.0.1");

    m_Server = new QTcpServer(this);
    m_RunTimer = new QTimer();
    m_ClientManager = new ClientManager(this);

    connect(m_Server, &QTcpServer::newConnection, this, &TCPServer::NewConnection);

    connect(m_ClientManager, &ClientManager::NewOperator, this, &TCPServer::SetOperator);

    connect(m_ClientManager, &ClientManager::IsOperator, this, [this](TCPClient*  client)
    {
        return m_Operator.get() == client;
    });

    connect(m_ClientManager, &ClientManager::NewAction, this, &TCPServer::NewAction);

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

    RunActionServer();

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

void TCPServer::SetOperator(TCPClient* newOperator)
{
    if(!newOperator) return;

    QString operators_name{newOperator->GetName().c_str()};

    if(m_Operator.get() == newOperator)
        Log(newOperator->GetName() + " is already operator", WARN_LEVEL_LOG);

    else if(m_Operator.get() != newOperator && newOperator->GetLevel() > 0)
    {
        m_Operator.reset(newOperator);
        Log("Operator assigned to " + newOperator->GetName(), INFO_LEVEL_LOG);
    }

    else if(m_Operator.get() != newOperator && newOperator->GetLevel() <= 0)
        Log(newOperator->GetName() + " have no permissions to get operator rights", WARN_LEVEL_LOG);
}

void TCPServer::NewAction(int idOfClient, Command *command)
{
    StartNewActionClient(*command, idOfClient);
}

std::unordered_map<std::string, std::function<void(void)>> TCPServer::GetActionFunctions()
{
    return{};
}

TCPServer::~TCPServer()
{
    SetRunning(false);
    delete(m_Server);
    delete(m_ClientManager);
    delete(m_RunTimer);
}