#include "matchgame.h"
#include "card.h"
#include "pile.h"
#include <QWidget>
#include "gameboard.h"
#include "game.h"
#include "cardmove.h"

extern gameboard *MainApp;

MatchGame::MatchGame(QWidget *par)
    :Game(par)
{
}

QString MatchGame::GameName()
{
    return "Match Game";
}

void MatchGame::ReDeal(hardtype h)
{
    Clear();
    Card* Deck[52];
    for(int i =0; i < 52; i++)
    {
        Deck[i] = new Card(i, parent);
        Deck[i]->Faceup(false);
    }
    Shuffle(Deck, 52);

    playOff[0] = new PilePlayOff(570, 640, 0, 0, parent);
    int k = 0;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<8 && k<52; j++, k++)
        {
            field[k] = new PileField(10+80*j, 10+105*i, 0, 0, parent);
        }
    }


    for(int i=0; i<52; i++)
    {
        Deck[i]->Move(field[i]);
    }
}


void MatchGame::OnFieldClick(Card *c)
{

}

