#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <QTcpServer>
#include <QTcpSocket>

#ifndef PACKET_HPP
#include "Packet.hpp"
#endif

class TCPClient : public QObject
{
Q_OBJECT
private:
    QTcpSocket *m_Socket;

    std::string m_Name{"NOT_SET"};

    int m_Id;
    int m_Level{0};
    bool m_TCPOnly{false};
    bool m_IsAlive{false};

    void Log(const std::string&message, int levelLog);

public slots:
    void GotMessage();

public:
    explicit TCPClient(QTcpSocket * clientSocket, int id,  QObject*parent = nullptr);

    void Start();

    void Disconnect();

    [[nodiscard]] const int& GetLevel() const;

    [[nodiscard]] const std::string& GetName() const;

    [[nodiscard]] const int& GetId() const;

    virtual ~TCPClient();

signals:
    void LogClient(const std::string&message, int levelLog);

    void SendMessageToServer(const QJsonObject& message);
};

#endif //TCP_CLIENT_HPP
