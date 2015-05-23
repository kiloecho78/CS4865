#ifndef PLAYER_H
#define PLAYER_H
#include "scorecard.h"
#include <QString>


class Player
{
private:
    QString name;
    Scorecard myScore;
    bool turn;


public:
    Player();
    ~Player();
};

#endif // PLAYER_H
