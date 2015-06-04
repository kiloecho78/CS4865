#include "gameserver.h"


GameServer::GameServer(QObject *parent) : QObject(parent)
{
    connect(&server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    server.listen(QHostAddress::Any, 8888);
}

void GameServer::acceptConnection()
{
    client = server.nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
}


GameServer::~GameServer()
{
    server.close();
}

void GameServer::startRead()
{
    char buffer[1024] = {0};
    client->read(buffer, client->bytesAvailable());
    client->close();
}

