#ifndef KLONDIKE_H
#define KLONDIKE_H
#include "game.h"
#include <QWidget>
class Pile;


class Klondike:public Game
{
    Pile *deal;
    Pile *dealt;
    Pile *playOff[4];
    Pile *field[7];
public:
    Klondike(QWidget *par);
    void ReDeal(hardtype h);
    QString GameName();
    void DealAction();
    void OnFieldClick(Card*c);
    void OnDealClick(Card*c);
    void OnDealtClick(Card*c);
};

#endif // KLONDIKE_H
