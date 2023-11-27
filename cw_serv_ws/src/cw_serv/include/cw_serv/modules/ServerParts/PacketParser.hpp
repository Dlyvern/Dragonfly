#ifndef PACKET_PARSER_HPP
#define PACKET_PARSER_HPP

#include "QObject"

#ifndef PACKET_HPP
#include "Packet.hpp"
#endif

class PacketParser : public QObject
{
    Q_OBJECT
private:

public:
    PacketParser();

    void Start(const QByteArray &socketData);

    virtual ~PacketParser();
signals:
    void NewPacket(Packet* packet);
};

#endif //PACKET_PARSER_HPP
