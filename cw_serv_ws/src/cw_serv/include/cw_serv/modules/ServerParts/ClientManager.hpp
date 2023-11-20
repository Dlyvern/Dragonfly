#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP

#include <QPointer>
#include "QWidget"

#ifndef TCP_CLIENT_HPP
#include "TCPClient.hpp"
#endif

#ifndef COMMAND_HPP
#include "cw_structs/Command.hpp"
#endif

class ClientManager : public QWidget
{
    Q_OBJECT
private:
    std::vector<std::shared_ptr<TCPClient>>m_TCPClients;

    bool DisconnectClient(TCPClient* tcpClient);

    void Log(const std::string&message, int logLevel, TCPClient* tcpClient) const;

public:

    explicit ClientManager(QWidget* parent = nullptr);

    void AddNewClient(std::shared_ptr<TCPClient>&&tcpClient);

    virtual ~ClientManager();

private slots:
    void MessageFromClient(const QJsonObject& message);

signals:
    void NewOperator(TCPClient* newOperator);

    bool IsOperator(TCPClient* maybeOperator);

    void NewAction(int idOfClient, Command*command);
};

#endif //CLIENT_MANAGER_HPP
