#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QString>
#include <QTcpSocket>

class GameClient : public QObject
{
    Q_OBJECT
public:
    explicit GameClient(QObject *parent = 0);
    ~GameClient();
    void start(QString address, quint16 port);
    QString package;
    int pkgsize;

signals:

public slots:
    void startTransfer();

private:
    QTcpSocket client;
};

#endif // GAMECLIENT_H
