#ifndef GAMESERVER_H
#define GAMESERVER_H


#include <QTcpServer>

class Connection;


class GameServer : public QTcpServer
{
    Q_OBJECT
public:
    GameServer(QObject *parent = 0);

public:
    Server(QObject *parent = 0);

signals:
    void newConnection(Connection *connection);

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
};

#endif // GAMESERVER_H
