#include "cardmove.h"
#include "card.h"
#include "pile.h"

QStack<Cardmove*> Cardmove::undostack;

Cardmove::Cardmove(Card *c, Pile *fr, Pile *t)
    :card(c), from(fr), to(t), count(0)
{
    wasFaceUp = c->Under()?c->Under()->Faceup():false;
    undostack.push(this);
}

Cardmove::Cardmove(int n):count(n)
{
    undostack.push(this);
}

void Cardmove::UndoMove()
{
    if(undostack.empty()) return;
    Cardmove *u = undostack.pop();
    int n = u->count;
    do
    {
        if(n)
        {
            delete u;
            u = undostack.pop();
        }
        if(u->from->Top() && u->from->Top()->Faceup() != u->wasFaceUp)
            u->from->Top()->Flip();
        u->from->AcceptCards(u->card,true,false);
        if(u->from->Type()==DEAL)u->card->Faceup(false);
        if(u->from->Type()==DEALT && n%3 ==0)u->card->AlignWithPile();
    }while(--n>0);
    delete u;
}

void Cardmove::Clear()
{
    int n = undostack.size();
    while(n-->0){
        undostack.pop();
    }
}
