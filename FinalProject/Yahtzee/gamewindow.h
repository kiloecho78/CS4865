#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "die.h"
#include "player.h"
#include "gameclient.h"
#include <QTime>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QQueue>
#include <QPalette>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::GameWindow *ui;
    bool topScoreSetArray[6];
    bool bottomScoreSetArray[7];
    int sectionsCompleted = 0;
    int diceVals[5] = {-1,-1,-1,-1,-1};
    int buttonToPaint = 0;
    Die *die1;
    Die *die2;
    Die *die3;
    Die *die4;
    Die *die5;
    Die *diceSet[5];
    Player *player1;
    Player *player2;
    Player *player3;
    Player *player4;
    Player *player5;
    Player *currentPlayer;
    QString host = "sn237s16";
    QPushButton *scoreButtonSet[13];
    QPushButton *rollButton;
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
    QLabel *scoreLabelSet[6];
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
    QTime t;
    QQueue <Player*>turnOrder;
    GameClient client;
    QString myNickName;
    QTextTableFormat tableFormat;

public slots:
    void appendMessage(const QString &from, const QString &message);
//    void pushButton(const QString &button, const QString &value);

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    bool goFish(int x);
    bool checkSmallStraight();
    void checkTopComplete();
    void checkBottomComplete();
    void createSet();
    void endTurn();
    void finalScore();
    void setColors(int playerNumber);
    void setUpScoreButtonArray();
    void setUpScoreLabelArray();
    void sortDice();
    void showDice();
    void playgame();

private slots:
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
    void on_action_Rules_triggered();
    void on_checkBox1_stateChanged(int arg1);
    void on_checkBox2_stateChanged(int arg1);
    void on_checkBox3_stateChanged(int arg1);
    void on_checkBox4_stateChanged(int arg1);
    void on_checkBox5_stateChanged(int arg1);
    void on_player1Button_clicked();
    void on_player2Button_clicked();
    void on_player3Button_clicked();
    void on_player4Button_clicked();
    void on_player5Button_clicked();
    void on_accept_clicked();
    void on_actionE_xit_triggered();
    void returnPressed();
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);
};

#endif // GAMEWINDOW_H
