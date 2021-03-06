#include <QtNetwork>
#include "gameclient.h"
#include "connection.h"
#include "peermanager.h"

static inline QByteArray IntToArray(qint32 source);

GameClient::GameClient()
{
    peerManager = new PeerManager(this);
    peerManager->setServerPort(server.serverPort());
    peerManager->startBroadcasting();

    QObject::connect(peerManager, SIGNAL(newConnection(Connection*)),
                     this, SLOT(newConnection(Connection*)));
    QObject::connect(&server, SIGNAL(newConnection(Connection*)),
                     this, SLOT(newConnection(Connection*)));

}

void GameClient::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return;

    QList<Connection *> connections = peers.values();
    foreach (Connection *connection, connections)
        connection->sendMessage(message);
}

/*void GameClient::sendButton(const QString &button, const QString &value)
{
    if (button.isEmpty() || value.isEmpty())
        return;

    QList<Connection *> connections = peers.values();
    foreach (Connection *connection, connections)
        connection->sendButton(button, value);
}*/

QString GameClient::nickName() const
{
    return QString(peerManager->userName()) + '@' + QHostInfo::localHostName()
           + ':' + QString::number(server.serverPort());
}

bool GameClient::hasConnection(const QHostAddress &senderIp, int senderPort) const
{
    if (senderPort == -1)
        return peers.contains(senderIp);

    if (!peers.contains(senderIp))
        return false;

    QList<Connection *> connections = peers.values(senderIp);
    foreach (Connection *connection, connections) {
        if (connection->peerPort() == senderPort)
            return true;
    }

    return false;
}

void GameClient::newConnection(Connection *connection)
{
    connection->setGreetingMessage(peerManager->userName());

    connect(connection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(connectionError(QAbstractSocket::SocketError)));
    connect(connection, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(connection, SIGNAL(readyForUse()), this, SLOT(readyForUse()));
}

void GameClient::readyForUse()
{
    Connection *connection = qobject_cast<Connection *>(sender());
    if (!connection || hasConnection(connection->peerAddress(),
                                     connection->peerPort()))
        return;

    connect(connection, SIGNAL(newMessage(QString,QString)),
            this, SIGNAL(newMessage(QString,QString)));
//    connect(connection, SIGNAL(newButtonPush(QString,QString)), this, SIGNAL(newButton(QString,QString)));

    peers.insert(connection->peerAddress(), connection);
    QString nick = connection->name();
    if (!nick.isEmpty())
        emit newParticipant(nick);
}

void GameClient::disconnected()
{
    if (Connection *connection = qobject_cast<Connection *>(sender()))
        removeConnection(connection);
}

void GameClient::connectionError(QAbstractSocket::SocketError /* socketError */)
{
    if (Connection *connection = qobject_cast<Connection *>(sender()))
        removeConnection(connection);
}

void GameClient::removeConnection(Connection *connection)
{
    if (peers.contains(connection->peerAddress())) {
        peers.remove(connection->peerAddress());
        QString nick = connection->name();
        if (!nick.isEmpty())
            emit participantLeft(nick);
    }
    connection->deleteLater();
}
