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
    bool topScoreSetArray[6];
    bool bottomScoreSetArray[7];
    int sectionsCompleted = 0;

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
    bool goFish(int x);
    bool checkSmallStraight();
    void checkTopComplete();
    void checkBottomComplete();
    void finalScore();
    void createSet();

private slots:
    void on_endTurn_clicked();
    void on_rollButton_clicked();
    void on_oneScore_clicked();
    void on_twoScore_clicked();
    void on_threeScore_clicked();
    void on_fourScore_clicked();
    void on_fiveScore_clicked();
    void on_sixScore_clicked();
    void on_toakScore_clicked();
    void on_foakScore_clicked();
    void on_fhScore_clicked();
    void on_smsScore_clicked();
    void on_lgsScore_clicked();
    void on_chanceScore_clicked();
    void on_yahtzeeScore_clicked();
    void on_die1_clicked();
    void on_die2_clicked();
    void on_die3_clicked();
    void on_die4_clicked();
    void on_die5_clicked();
};

#endif // GAMEWINDOW_H
