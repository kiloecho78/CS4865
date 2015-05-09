#include "game.h"
#include "pile.h"
#include "card.h"
#include "winningdialog.h"
#include "cardmove.h"

extern WinningDialog *WinBox;

Game::Game(QWidget *par)
    :parent(par)
{}

Game::~Game()
{
    Clear();
}

void Game::Clear()
{
    while(!piles.empty())
    {
        Pile *p = piles.takeLast();
        if (p) delete p;
    }
}

void Game::CheckWin()
{
    int i = piles.count();
    bool allEmpty = true;
    while(allEmpty && i>=0 &&piles[--i]->Type()!=PLAYOFF)
        allEmpty = piles[i]->Empty();
    if(allEmpty)
    {
        WinBox->show();
        Cardmove::Clear();
    }
}

void Game::AddPile(Pile *p)
{
    piles.append(p);
}

bool Game::PlayOff(Card* c)
{
    if(c->Pilep() && c->Pilep()->CanBeDragged(c))
    {
        int i = 0;
        while(i<piles.count() && piles[i] &&
              !(piles[i]->Type() == PLAYOFF &&
                piles[i]->CanBeDropped(c)))
            i++;
        if(i < piles.count())
        {
            piles[i]->AcceptCards(c);
            return true;
        }
    }
    return false;
}

void Game::PlayOffAll()
{
    bool cardFound;
    do
    {
        cardFound = false;
        int n = 0;
        int m = piles.count();
        while(n<m)
        {
            if(piles[n]->Type() > DEAL && piles[n]->Top())
                cardFound |= PlayOff(piles[n]->Top());
            n++;
        }
    }while(cardFound);
}

