#include "gameclient.h"

GameClient::GameClient(QObject *parent) : QObject(parent)
{
    connect(&client, SIGNAL(connected()), this,  SLOT(startTransfer()));
}

GameClient::~GameClient()
{
    client.close();
}

void GameClient::start(QString address, quint16 port)
{
    QHostAddress addr(address);
    client.connectToHost(addr, port);
}

void GameClient::startTransfer()
{
    client.write("Hello Host", 10);
}

