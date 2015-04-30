#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include<QList>
enum hardtype {REPEAT, EASY, MEDIUM, HARD};
class Pile;
class Card;

class Game
{
protected:
    QWidget *parent;
    QList<Pile*> piles;
public:
    Game(QWidget *par);
    virtual ~Game();
    void Clear();
    virtual void CheckWin();
    void AddPile(Pile *p);
    virtual int FreeMoves(){return 0;}//calculates
    virtual void ReDeal(hardtype h = REPEAT) = 0;

};

//piles created after the cards
#endif // GAME_H
