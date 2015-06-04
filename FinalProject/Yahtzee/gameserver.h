#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include <QtCore>
#include <QTcpSocket>
#include <QTcpServer>
#include <QtNetwork>

class GameServer : public QObject
{
    Q_OBJECT
public:
    explicit GameServer(QObject *parent = 0);

signals:
    void dataReceived(QByteArray);

public slots:
    void newConnection();
    void disconnected();
    void readyRead();

private:
    QTcpServer *server;
    QHash<QTcpSocket*, QByteArray*> buffers;
    QHash<QTcpSocket*, qint32*> sizes;
};

#endif // GAMESERVER_H
