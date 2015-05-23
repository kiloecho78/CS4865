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
    QPushButton *scoreButtonSet[13];
    QLabel *scoreLabelSet[6];
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
    QPushButton *oneScore;
    QPushButton *twoScore;
    QPushButton *threeScore;
    QPushButton *fourScore;
    QPushButton *fiveScore;
    QPushButton *sixScore;
    QPushButton *threeOfAKindScore;
    QPushButton *fourOfAKindScore;
    QPushButton *fullHouseScore;
    QPushButton *smStraightScore;
    QPushButton *lgStraightScore;
    QPushButton *chanceScore;
    QPushButton *yahtzeeScore;
    QLabel *one;
    QLabel *two;
    QLabel *three;
    QLabel *four;
    QLabel *five;
    QLabel *six;
    QLabel *toak;
    QLabel *foak;
    QLabel *fh;
    QLabel *sms;
    QLabel *lgs;
    QLabel *chance;
    QLabel *yahtzee;
    QLabel *topSubTotal;
    QLabel *bonus;
    QLabel *topGrandTotal;
    QLabel *bottomSubTotal;
    QLabel *topGrandTotal2;
    QLabel *grandTotal;
    QLabel *topSubTotalScore;
    QLabel *bonusScore;
    QLabel *topGrandTotalScore;
    QLabel *bottomSubTotalScore;
    QLabel *topGrandTotal2Score;
    QLabel *grandTotalScore;
    QLabel *gameColHeader;
    QLabel *playerNameColHeader;

public:
    explicit GameWindow(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);
    ~GameWindow();
    void sortDice();
    void showDice();
    void setUpScoreButtonArray();
    void setUpScoreLabelArray();

private slots:
    void on_endTurn_clicked();
    

    void on_rollButton_clicked();
};

#endif // GAMEWINDOW_H
