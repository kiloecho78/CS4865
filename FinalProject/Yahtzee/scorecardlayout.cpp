#include "scorecardlayout.h"

ScorecardLayout::ScorecardLayout()
{
    oneScore = new QPushButton();
    oneScore->setFlat(true);
    twoScore = new QPushButton();
    twoScore->setFlat(true);
    threeScore = new QPushButton();
    threeScore->setFlat(true);
    fourScore = new QPushButton();
    fourScore->setFlat(true);
    fiveScore = new QPushButton();
    fiveScore->setFlat(true);
    sixScore = new QPushButton();
    sixScore->setFlat(true);
    threeOfAKindScore = new QPushButton();
    threeOfAKindScore->setFlat(true);
    fourOfAKindScore = new QPushButton();
    fourOfAKindScore->setFlat(true);
    fullHouseScore = new QPushButton();
    fullHouseScore->setFlat(true);
    smStraightScore = new QPushButton();
    smStraightScore->setFlat(true);
    lgStraightScore = new QPushButton();
    lgStraightScore->setFlat(true);
    chanceScore = new QPushButton();
    chanceScore->setFlat(true);
    yahtzeeScore = new QPushButton();
    yahtzeeScore->setFlat(true);
    one = new QLabel(QString("Aces"));
    two = new QLabel(QString("Twos"));
    three = new QLabel(QString("Threes"));
    four = new QLabel(QString("Fours"));
    five = new QLabel(QString("Fives"));
    six = new QLabel(QString("Sixes"));
    toak = new QLabel(QString("Three of a Kind"));
    foak = new QLabel(QString("Four of a Kind"));
    fh = new QLabel(QString("Full House"));
    sms  = new QLabel(QString("Small Straight"));
    lgs = new QLabel(QString("Large Straight"));
    chance = new QLabel(QString("Chance"));
    yahtzee = new QLabel(QString("YAHTZEE"));
    topSubTotal = new QLabel(QString("TOTAL SCORE"));
    bonus = new QLabel(QString("BONUS if total score is 63 or more"));
    topGrandTotal = new QLabel(QString("TOTAL of Upper Section"));
    bottomSubTotal = new QLabel(QString("TOTAL of Lower Section"));
    topGrandTotal2 = new QLabel(QString("TOTAL of Upper Section"));
    grandTotal = new QLabel(QString("GRAND TOTAL"));
    gameColHeader = new QLabel(QString("Yahtzee!"));
    QFont f("Arial", 14, QFont::Bold);
    gameColHeader->setFont(f);
    playerNameColHeader = new QLabel(QString(""));
    scorecardLayout->addWidget(gameColHeader,0,0,2,2);
    scorecardLayout->addWidget(playerNameColHeader,0,1);
    scorecardLayout->addWidget(one,1,0);
    scorecardLayout->addWidget(two,2,0);
    scorecardLayout->addWidget(three,3,0);
    scorecardLayout->addWidget(four,4,0);
    scorecardLayout->addWidget(five,5,0);
    scorecardLayout->addWidget(six,6,0);
    scorecardLayout->addWidget(topSubTotal,7,0);
    scorecardLayout->addWidget(bonus,8,0);
    scorecardLayout->addWidget(topGrandTotal,9,0);
    scorecardLayout->addWidget(toak,10,0);
    scorecardLayout->addWidget(foak,11,0);
    scorecardLayout->addWidget(fh,12,0);
    scorecardLayout->addWidget(sms,13,0);
    scorecardLayout->addWidget(lgs,14,0);



}

ScorecardLayout::~ScorecardLayout()
{

}

