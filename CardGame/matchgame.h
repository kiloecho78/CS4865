#ifndef MATCHGAME_H
#define MATCHGAME_H
#include "game.h"
#include <QWidget>
class Pile;


class MatchGame:public Game
{
    Pile *playOff[1];
    Pile *field[52];
    Card *first = NULL;
    Card *second = NULL;
public:
    MatchGame(QWidget *par);
    QString GameName();
    void ReDeal(hardtype h);
    void OnFieldClick(Card*c);
};

#endif // MATCHGAME_H
