#include "gameclient.h"

static inline QByteArray IntToArray(qint32 source);

GameClient::GameClient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

bool GameClient::connectToHost(QString host)
{
    socket->connectToHost(host, 7878);
    return socket->waitForConnected();
}

bool GameClient::writeData(QByteArray data)
{
    if(socket->state()==QAbstractSocket::ConnectedState)
    {
        socket->write(IntToArray(data.size()));
        socket->write(data);
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

QByteArray IntToArray(qint32 source)
{
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data<<source;
    return temp;
}
