#ifndef SCORECARDLAYOUT_H
#define SCORECARDLAYOUT_H
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


class ScorecardLayout
{
private:
    QGridLayout *scorecardLayout;
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
    QLabel *gameColHeader;
    QLabel *playerNameColHeader;
public:
    ScorecardLayout();
    ~ScorecardLayout();
    friend class GameWindow;
};

#endif // SCORECARDLAYOUT_H
