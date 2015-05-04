#include "matchgame.h"
#include "card.h"
#include "pile.h"
#include <QWidget>
#include "gameboard.h"
#include "cardmove.h"

extern gameboard *MainApp;

MatchGame::MatchGame(QWidget *par)
{
    Card *Deck[52];
    //PileField *Places[4];
    Shuffle(Deck, 52);
    /*for(int j =0; j<52; j++)
    {
        if(j<11){
            Places[j] = new PileField(5+(j*71), 5, 0, 0, par);
        }
        else if((j>=11)&&(j<22)){
            Places[j] = new PileField(5+(j*71), 106, 0, 0, par);
        }
        else if((j>=22)&&(j<33)){
            Places[j] = new PileField(5+(j*71), 207, 0, 0, par);
        }
        else if((j>=33)&&(j<44)){
            Places[j] = new PileField(5+(j*71), 308, 0, 0, par);
        }
        else if((j>=44)){
            Places[j] = new PileField(5+(j*71), 409, 0, 0, par);
        }
    }
    for(int i =0; i<52; i++)
    {
        Deck[i] = new Card(i);
        Places[i]->AcceptCards(Deck[i],expose,true);
    }*/
}

QString MatchGame::GameName()
{
    return "Match";
}

void MatchGame::DealAction()
{

}

//void MatchGame::OnFieldClick(Card *c)
//{

//}

