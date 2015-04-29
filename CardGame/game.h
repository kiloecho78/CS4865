#ifndef GAME_H
#define GAME_H
#include "card.h"
//edit to remove

class Game
{
public:
    Game(QWidget *par);
    ~Game();
    void CheckWin();
    void AddPile(Pile *p);
    int FreeMoves();
};


#endif // GAME_H
