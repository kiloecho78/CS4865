#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QtNetwork>

class GameServer : public QObject
{
    Q_OBJECT
public:
    explicit GameServer(QObject *parent = 0);
    ~GameServer();

signals:

public slots:
    void startRead();
    void acceptConnection();

private:
    QTcpServer server;
    QTcpSocket* client;
};

#endif // GAMESERVER_H
