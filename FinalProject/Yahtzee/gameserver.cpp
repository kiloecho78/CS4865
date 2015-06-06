#include <QtNetwork>

#include "connection.h"
#include "gameserver.h"

GameServer::GameServer(QObject *parent)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any);
}

void GameServer::incomingConnection(qintptr socketDescriptor)
{
    Connection *connection = new Connection(this);
    connection->setSocketDescriptor(socketDescriptor);
    emit newConnection(connection);
}
