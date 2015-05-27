#ifndef SCORECARD_H
#define SCORECARD_H
#include <QString>


class Scorecard
{
public:
    QString playerName;
    int ones = -1;
    int twos = -1;
    int threes = -1;
    int fours = -1;
    int fives = -1;
    int sixes = -1;
    int topSubTotal;
    int bonus;
    int topTotal;
    int threeOfAKind = -1;
    int fourOfAKind = -1;
    int fullHouse = -1;
    int smStraight = -1;
    int lgStraight = -1;
    int chance = -1;
    int yahtzee = -1;
    int extraYahtzee = -1;
    int bottomSubTotal;
    int grandTotal;
    bool topScoreSetArray[6];
    bool bottomScoreSetArray[7];

public:
    Scorecard();
    ~Scorecard();
    void computeScores();

};

#endif // SCORECARD_H
