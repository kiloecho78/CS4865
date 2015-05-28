#ifndef PLAYER_H
#define PLAYER_H
#include "scorecard.h"
#include <QString>


class Player
{
private:
    QString myname;
    Scorecard myScore;
    bool turn;
    QString ip;
    int rolls;
    int playerNum;


public:
    Player(QString name, int i);
    ~Player();
    void getMyScore();
    friend class GameWindow;
};

#endif // PLAYER_H
