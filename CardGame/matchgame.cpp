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

    playOff[0] = new PilePlayOff(820, 10, 0, 0, parent);

    for(int i=0; i<52; i++)
     {}   //field[i] = new PileField()
}


void MatchGame::OnFieldClick(Card *c)
{

}

