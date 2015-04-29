#ifndef MATCHGAME_H
#define MATCHGAME_H
#include <QWidget>
class Pile;


class MatchGame
{
    Pile *playoff[1];
    Pile *field[52];
public:
    MatchGame(QWidget *par);
    QString GameName();
    void DealAction();
    //void OnFieldClick(Card*c);
};

#endif // MATCHGAME_H
