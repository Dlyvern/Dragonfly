#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include "QTimer"

#ifndef MODULE_HPP
#include "Module.hpp"
#endif

#ifndef TCP_CLIENT_HPP
#include "ServerParts/TCPClient.hpp"
#endif                                  

#ifndef CLIENT_MANAGER_HPP
#include "ServerParts/ClientManager.hpp"
#endif

#include "QTcpServer"
#include "QTcpSocket"

class TCPServer : public Module
{
    Q_OBJECT
private:
    QTimer *m_RunTimer{nullptr};

    ClientManager* m_ClientManager{nullptr};
    int m_Port;
    QHostAddress m_Ip;
    QTcpServer *m_Server;

    std::shared_ptr<TCPClient> m_Operator{nullptr};

    int m_IdOfClient{0};

private slots:
    void NewConnection();

    void LogMessageFromClient(const std::string&message, int levelLog);

    void SetOperator(TCPClient* newOperator);

    void NewAction(int idOfClient, Command*command);

    void Run() override;

public:
    explicit TCPServer(const std::string &name, QWidget *parent = nullptr);

    void Start() override;

    [[nodiscard]]std::unordered_map<std::string, std::function<void(void)>> GetActionFunctions() override;

    virtual ~TCPServer();
};
#endif //TCP_SERVER_HPP