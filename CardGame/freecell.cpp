#include "freecell.h"
#include "pile.h"
#include "card.h"
//Test Mac to School
Freecell::Freecell(QWidget *par)
    :Game(par)
{
}

int Freecell::FreeMoves()
{
    int f = 0, n =0;
    for(int i = 0; i<4; i++) f+=freeCell[i]->Empty();
    for(int i = 0; i<8; i++) n+=field[i]->Empty();
    int fm = (f+1)<<n;
    return fm;
}

void Freecell::ReDeal(hardtype h)
{
    Clear();
    Card* Deck[52];
    for(int i=0; i<52;i++)
    {
        Deck[i] = new Card(i,parent);
        Deck[i]->Faceup(true);
        Deck[i]->move(360,420);
    }
    Shuffle(Deck, 52);


    for(int i=0; i<4; i++)
        playOff[i] = new PilePlayOff(360+80*i, 10, 0, 0, parent);
    playOff[0]->AddDropRules(4,
                             new RuleStackSameSuit,
                             new RuleStackPlusOne,
                             new RuleBaseAce,
                             new RuleMoveOneAtATime);
    playOff[0]->AddDragRules(1, new RuleMoveNone);

    for(int i = 0; i<4; i++)
        freeCell[i] = new PileFreeCell(20+80*i, 10, 0, 0, parent);
    freeCell[0]->AddDropRules(1,
                              new RuleNoStack);

    for(int i=0; i<8; i++)
        field[i] = new PileField(20+82*i,120,0,18,parent);
    field[0]->AddDropRules(3, new RuleStackAlternateColor,
                           new RuleStackLengthLimited,
                           new RuleStackMinusOne);
    field[0]->AddDragRules(3,
                           new RuleMoveLenghtLimited,
                           new RuleMoveAltColor,
                           new RuleMoveSeqDecreasing);

    for(int i=0;i<52;i++)
        Deck[i]->Move(field[i%8]);
}

QString Freecell::GameName()
{
    return "Freecell";
}

void Freecell::OnFieldClick(Card *c)
{
    if(c) PlayOff(c);
}

void Freecell::DealAction()
{

}

