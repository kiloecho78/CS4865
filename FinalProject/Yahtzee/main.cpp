#include "gamewindow.h"
#include "rulesdialog.h"
#include "gameclient.h"
#include "gameserver.h"
#include <QApplication>

RulesDialog *Rules;
GameClient *Client;
GameServer *Server;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    RulesDialog rd;
    GameClient c;
    GameServer s;
    w.show();
    Rules = &rd;
    Client = &c;
    Server = &s;
    return a.exec();
}
