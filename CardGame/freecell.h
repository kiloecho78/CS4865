#ifndef FREECELL_H
#define FREECELL_H
#include "game.h"
#include <QString>
#include <QWidget>
class Pile;


class Freecell:public Game
{
    Pile* field[8];
    Pile* freeCell[4];
    Pile* playOff[4];
public:
    Freecell(QWidget *par);
    void ReDeal(hardtype h);
    void PlayOff(bool all = false);
    void DealAction();
    QString GameName();
    void OnFieldClick(Card *c);
    int FreeMoves();
};

#endif // FREECELL_H
