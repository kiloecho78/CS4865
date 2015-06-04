#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QtCore>
#include <QString>
#include <QTcpSocket>

class GameClient : public QObject
{
    Q_OBJECT
public:
    explicit GameClient(QObject *parent = 0);
    QString package;
    int pkgsize;

public slots:
    bool connectToHost(QString host);
    bool writeData(QByteArray data);

private:
    QTcpSocket *socket;
};

#endif // GAMECLIENT_H
