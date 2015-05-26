#include "gamewindow.h"
#include "rulesdialog.h"
#include <QApplication>

RulesDialog *Rules;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    RulesDialog rd;
    w.show();
    Rules = &rd;

    return a.exec();
}
