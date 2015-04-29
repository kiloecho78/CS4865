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

void Klondike::ReDeal()
{
    //Clear();
    // create and shuffle deck;
    Card* Deck[52];
    for(int i = 0; i<52; i++)
        Deck[i] = new Card(i); //create facedown
    Shuffle(Deck,52);
    //now create board layout.
/*    for(int i=0; i<4; i++)

        playOff[i]= new PilePlayOff(266+82*i, 10,0,0,parent);
    playOff[0]->AddDropRules(4,new RuleStackSameSlot(),
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
            Deck[i++]->Move(field(pile));
        }
    while(i<52)
        Deck[i++]->Move(deal);
*/}

void Klondike::DealAction()
{

}

void Klondike::OnFieldClick(Card *c)
{

}

void Klondike::OnDealClick(Card *c)
{

}

void Klondike::OnDealtClick(Card *c)
{

}
