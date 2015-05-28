#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "die.h"
#include <QTime>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QQueue>
#include "player.h"

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
    Die *die1;
    Die *die2;
    Die *die3;
    Die *die4;
    Die *die5;
    QPushButton *rollButton;
//    QPushButton *endTurn;
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
    bool topScoreSetArray[6];
    bool bottomScoreSetArray[7];
    int sectionsCompleted = 0;
    QQueue <Player*>turnOrder;
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
    Player *player1;
    Player *player2;
    Player *player3;
    Player *player4;
    Player *player5;
    Player *currentPlayer;

public:
    explicit GameWindow(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);
    ~GameWindow();
    void sortDice();
    void showDice();
    void setUpScoreButtonArray();
    void setUpScoreLabelArray();
    bool goFish(int x);
    bool checkSmallStraight();
    void checkTopComplete();
    void checkBottomComplete();
    void finalScore();
    void createSet();
    void playgame();
    void endTurn();

private slots:
//    void endTurn_clicked();
    void rollButton_clicked();
    void oneScore_clicked();
    void twoScore_clicked();
    void threeScore_clicked();
    void fourScore_clicked();
    void fiveScore_clicked();
    void sixScore_clicked();
    void toakScore_clicked();
    void foakScore_clicked();
    void fhScore_clicked();
    void smsScore_clicked();
    void lgsScore_clicked();
    void chanceScore_clicked();
    void yahtzeeScore_clicked();
    void die1_clicked();
    void die2_clicked();
    void die3_clicked();
    void die4_clicked();
    void die5_clicked();
    void on_action_Rules_triggered();
    void on_checkBox1_stateChanged(int arg1);
    void on_checkBox2_stateChanged(int arg1);
    void on_checkBox3_stateChanged(int arg1);
    void on_checkBox4_stateChanged(int arg1);
    void on_checkBox5_stateChanged(int arg1);
};

#endif // GAMEWINDOW_H
