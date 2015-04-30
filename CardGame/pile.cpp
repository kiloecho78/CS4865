#include "pile.h"
#include "card.h"
#include "gameboard.h"
#include "cardmove.h"

extern gameboard *MainApp;
extern Game *game;
extern QList<Pile*> piles;

//static member data
Rule *PileDeal::dragRules[DRAGLAST];
Rule *PileDeal::dropRules[DROPLAST];

Rule *PilePlayOff::dragRules[DRAGLAST];
Rule *PilePlayOff::dropRules[DROPLAST];

Rule *PileField::dragRules[DRAGLAST];
Rule *PileField::dropRules[DROPLAST];

Rule *PileFreeCell::dragRules[DRAGLAST];
Rule *PileFreeCell::dropRules[DROPLAST];

Rule *PileDealt::dragRules[DRAGLAST];
Rule *PileDealt::dropRules[DROPLAST];
//constructor
Pile::Pile(int x, int y,
           int dx, int dy,
           QWidget *parent):
    QLabel(parent), delta(QPoint(dx,dy)),top(0), bottom(0)
{
    game->AddPile(this);
    move(x,y);
    resize(71,96);
    setFrameShape(Box);
    setLineWidth(2);
    this->pallete().setColor(BACKGROUND_BLUE,BLACK);
    show();
}

Pile::~Pile()
{
    Card *c = bottom;
    while (c)
    {
        bottom = c->over;
            //c->setParent(NULL);
            delete c;
            c = bottom;
    }

}

void Pile::AcceptCards(Card* c, bool expose, bool record)
{
    QPoint cardPosition;
//    if(record) new CardMove(c, c->pile, this);
    if(c->pile) //is the card in a pile now?
        c->pile->ReleaseCards(c, expose);
    if(top) //pile not empty
    {
        c->under = top;
        top->over = c;
        cardPosition = top->pos() + (delta/((top->faceup)?1:2));
    }else{ //pile empty
        cardPosition = pos();
        bottom = c;
        c->under = NULL;
    }
    c->pile = this;
    top = c->AdjustPositions(cardPosition, delta);
//    if(c->pip == KING && Type()==PLAYOFF) game->CheckWin();
}

void Pile::ReleaseCards(Card *c, bool expose)
{
    //
//}






















//    va_end(lp);
}

void Pile::AddDropRules(int n ...)
{
    va_list lp;
    va_start(lp,n);

    int i=0;
    while(i<n)
        DropRule(i++, va_arg(lp, Rule*));
    DropRule(i, NULL);
    va_end(lp);
}

void Pile::AddDragRules(int n ...)
{
    va_list lp;
    va_start(lp, n);


    int i=0;
    while(i<n)
        DragRule(i++, va_arg(lp, Rule*));
    DragRule(i, NULL);
    va_end(lp);
}

void Pile::mouseReleaseEvent(QMouseEvent *ev)
{

}


bool Pile::CanBeDropped(Card *c)
{
    int i = 0;
    bool ok = true;
    while(ok && DropRule(i))
        ok = DropRule(i++)->Enforce(this, c);
    return ok;
}

void Pile::FindClosestDrop(Card *c)
{

}



bool Pile::CanBeDragged(Card *c)
{
    int i = 0;
    bool ok = true;
    while(ok && DragRule(i))
        ok = DragRule(i++)->Enforce(this, c);
    return ok;
}

