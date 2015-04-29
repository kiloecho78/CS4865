#include "gameboard.h"
#include "aboutdialog.h"
#include "winningdialog.h"
#include "help.h"
#include <QtPlugin>
#include <QApplication>

gameboard *MainApp;
WinningDialog *WinBox;
AboutDialog *About;
Help *help;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameboard w;
    WinningDialog wb;
    AboutDialog ad;
    Help hd;
    MainApp = &w;
    WinBox = &wb;
    About = &ad;
    help = &hd;
    w.show();

    return a.exec();
}
