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


public:
    Player(QString name);
    ~Player();
    void getMyScore();
    friend class GameWindow;
};

#endif // PLAYER_H
