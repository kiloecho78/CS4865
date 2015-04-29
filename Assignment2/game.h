#ifndef GAME_H
#define GAME_H
#include "card.h"

class Game
{
public:
    Game(QWidget *par);
    ~Game();
    int FreeMoves();
    void AddPile(Pile *p);
    void CheckWin();
};


#endif // GAME_H
