#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "die.h"
#include <QTime>
#include<QLineEdit>
#include <QPushButton>
#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::GameWindow *ui;
    Die *diceSet[5];
    QTime t;
    QPushButton *die1;
    QPushButton *die2;
    QPushButton *die3;
    QPushButton *die4;
    QPushButton *die5;
    QPushButton *rollButton;
    QPushButton *endTurn;
    QLineEdit *dice1;
    QLineEdit *dice2;
    QLineEdit *dice3;
    QLineEdit *dice4;
    QLineEdit *dice5;

public:
    explicit GameWindow(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);
    ~GameWindow();
    void sortDice();
    void showDice();

private slots:
    void on_endTurn_clicked();
    

    void on_rollButton_clicked();
};

#endif // GAMEWINDOW_H
