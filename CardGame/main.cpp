#include "gameboard.h"
#include "aboutdialog.h"
#include "winningdialog.h"
#include "help.h"
#include "preferencespage.h"
#include <QtPlugin>
#include <QApplication>

gameboard *MainApp;
WinningDialog *WinBox;
AboutDialog *About;
PreferencesPage *Prefs;
Help *help;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameboard w;
    WinningDialog wb;
    PreferencesPage pp;
    AboutDialog ad;
    Help hd;
    MainApp = &w;
    WinBox = &wb;
    About = &ad;
    help = &hd;
    Prefs = &pp;
    w.show();

    return a.exec();
}
