#include "klondike.h"
#include "card.h"
#include "pile.h"
#include <QWidget>
#include "gameboard.h"
#include "game.h"
#include "cardmove.h"

extern gameboard *MainApp;

Klondike::Klondike(QWidget *par)
    :Game(par)
{
}
QString Klondike::GameName()
{
    return "Klondike";
}

void Klondike::ReDeal(hardtype h)
{
    Clear();
    // create and shuffle deck;
    Card* Deck[52];
    for(int i = 0; i<52; i++)
        Deck[i] = new Card(i, parent); //create facedown
    Shuffle(Deck,52);
    //now create board layout.
    for(int i=0; i<4; i++)

        playOff[i]= new PilePlayOff(266+82*i, 10,0,0,parent);
    playOff[0]->AddDropRules(4,new RuleStackSameSuit(),
                             new RuleStackPlusOne(),
                             new RuleBaseAce(),
                             new RuleMoveOneAtATime());
    playOff[0]->AddDragRules(0);
    for(int i=0; i<7; i++)
        field[i] = new PileField(20+82*i,120,0,18,parent);
    field[0]->AddDropRules(3,
                           new RuleStackAlternateColor(),
                           new RuleBaseKing(),
                           new RuleStackMinusOne());
    field[0]->AddDragRules(2,
                           new RuleMoveSeqDecreasing(),
                           new RuleMoveAltColor());
    deal= new PileDeal(20,10,0,0,parent);
    deal->AddDropRules(2,
                       new RuleBaseNone(),
                       new RuleNoStack());
    deal->AddDragRules(1, new RuleMoveNone());
    dealt = new PileDealt(100,10,16,1, parent);
    dealt->AddDropRules(2,
                        new RuleBaseNone(),
                        new RuleNoStack());
    dealt->AddDragRules(1,new RuleMoveOneAtATime());
    //now deal the cards
    int i=0;
    for(int pass=0;pass<7;pass++)
        for(int pile = pass; pile < 7; pile++)
        {
            if(pass == pile)
                Deck[i]->Flip();
            Deck[i++]->Move(field[pile]);
        }
    while(i<52)
        Deck[i++]->Move(deal);
}

void Klondike::DealAction()
{
    Pile *p = deal;
    int n  0;
    if(deal->Top())
    {   Card *c = deal->Top();
        c->Faceup(true);
        dealt->AcceptCards(c,MainApp->Deal3(),true);
        n++;
        c->AlignWithPile();
        if(MainApp->Deal3())
        {
            if(deal->Top()){dealt->AcceptCards(deal->Top(),true, true); n++;}
            if(deal->Top()){dealt->AcceptCards(deal->Top(), false, true);n++;}
        }
    }else{//no cards left to deal means recycle the dealt pile
        while(dealt->Top())}
}

void Klondike::OnFieldClick(Card *c)
{

}

void Klondike::OnDealClick(Card *c)
{
    for(int i = 0; i<3; i++)
    {
        deal->Top()->Move(dealt);
    }
}

void Klondike::OnDealtClick(Card *c)
{

}
