#include "yahtzee.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Yahtzee w;
    w.show();

    return a.exec();
}
