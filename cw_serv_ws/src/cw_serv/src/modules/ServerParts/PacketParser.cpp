#include "modules/ServerParts/PacketParser.hpp"

PacketParser::PacketParser()
{

}

void PacketParser::Start(const QByteArray &socketData)
{
//    if (socketData.size() < 11)
//    {
//        qDebug() << "Invalid packet size";
//        return;
//    }
//
//    qint16 header;
//    quint8 type;
//    quint16 number;
//    quint16 lengthOfData;
//    QJsonObject jsonData;
//    quint16 crc;
//
//    QDataStream stream(socketData);
//
//    stream >> header >> type >> number >> lengthOfData;
//
//    QByteArray jsonDataBytes = socketData.mid(stream.device()->pos(), lengthOfData);
//
//    jsonData = QJsonDocument::fromJson(jsonDataBytes).object();
//
//    if(!stream.device()->seek(stream.device()->pos() + lengthOfData))
//        qDebug() << "Got broken message";
//
//    stream >> crc;

    Packet* packet = new Packet;

//    packet = new Packet(header, type, number, lengthOfData, std::move(jsonData), crc);

    packet->Unpack(socketData);

    emit NewPacket(packet);
}

PacketParser::~PacketParser() = default;
