#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QAbstractSocket>
#include <QHash>
#include <QHostAddress>
#include "gameserver.h"

class PeerManager;

class GameClient : public QObject
{
    Q_OBJECT
public:
    GameClient();

    void sendMessage(const QString &message);
    QString nickName() const;
    bool hasConnection(const QHostAddress &senderIp, int senderPort = -1) const;

signals:
    void newMessage(const QString &from, const QString &message);
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);

private slots:
    void newConnection(Connection *connection);
    void connectionError(QAbstractSocket::SocketError socketError);
    void disconnected();
    void readyForUse();

private:
    void removeConnection(Connection *connection);

    PeerManager *peerManager;
    GameServer server;
    QMultiHash<QHostAddress, Connection *> peers;
};

#endif // GAMECLIENT_H
