#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <QTcpSocket>

#ifndef PACKET_HPP
#include "Packet.hpp"
#endif

#include "actions/ActionClient.hpp"

class TCPClient : public QObject
{
Q_OBJECT
private:
    std::shared_ptr<ActionClient>m_ActionClient{nullptr};
    QTcpSocket *m_Socket;

    std::string m_Name{"NOT_SET"};

    int m_Id;
    int m_Level{0};
    bool m_TCPOnly{false};
    bool m_IsAlive{false};
    bool m_Operator{false};

    void Log(const std::string&message, int levelLog);

    void ActionDoneCallback(const std::string& resultArgs, bool result);

private slots:
    void ReadMessage();

public:
    explicit TCPClient(QTcpSocket * clientSocket, int id,  QObject*parent = nullptr);

    void Start();

    void Disconnect();

    [[nodiscard]] const int& GetLevel() const;

    [[nodiscard]] const std::string& GetName() const;

    [[nodiscard]] const int& GetId() const;

    void SendMessageToClient(const QJsonObject& message);

    virtual ~TCPClient();

signals:
    void LogClient(const std::string&message, int levelLog);

    void SendMessageToServer(const QJsonObject& message);
};

#endif //TCP_CLIENT_HPP
