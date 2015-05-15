#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "die.h"

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void

private:
    Ui::GameWindow *ui;
    Die *dice[5];
};

#endif // GAMEWINDOW_H
