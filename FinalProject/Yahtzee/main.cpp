#include "gamewindow.h"
#include "rulesdialog.h"
#include "getplayernamedialog.h"
#include <QApplication>

RulesDialog *Rules;
GetPlayerNameDialog *PName;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    RulesDialog rd;
    GetPlayerNameDialog pn;
    w.show();
    Rules = &rd;
    PName = &pn;

    return a.exec();
}
