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
//    this->palette().setColor(BACKGROUND_BLUE, BLACK);
    show();
}

Pile::~Pile()
{
    Card *c = bottom;
    while (c)
    {
        bottom = c->over;
            c->setParent(NULL);
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
    if(c->pip == KING && Type()==PLAYOFF) game->CheckWin();
}

void Pile::ReleaseCards(Card *c, bool expose)
{
    if(c && c->pile && c->pile==this)
    {
        if(c->under)
        {
            top=c->under;
            top->over = NULL;
            top->under = NULL;
            if(expose) top->Faceup(true);
        }else{
// unknown
        }
    }
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


bool Pile::CanBeDropped(Card *c)
{
    int i = 0;
    bool ok = true;
    while(ok && DropRule(i))
        ok = DropRule(i++)->Enforce(this, c);
    return ok;
}



bool Pile::CanBeDragged(Card *c)
{
    int i = 0;
    bool ok = true;
    while(ok && DragRule(i))
        ok = DragRule(i++)->Enforce(this, c);
    return ok;
}
/*










Probably a removed function
Unknown check to see if something is missing









*/
void Pile::FindClosestDrop(Card *c)
{
    const int NUM=3;
    QPoint drop = c->pos();
    Pile *closest[NUM]={NULL,NULL,NULL};
    int distance[NUM]={10000,20000,30000};
    for(int i =0; i<game->piles.count(); i++)
    {
        Pile *p = game->piles[i];
        if(p == c->pile)continue;
        QPoint diff = drop - (p->top?p->top->pos():p->pos());
        int dist = diff.manhattanLength();
        for (int j=0;j<NUM;j++)
        {
            if(dist<distance[j])
            {

            }









            closest[i]->AcceptCards(c);
            return;
        }
    }
    QPoint p = c->under?(c->under->pos()+c->pile->Delta()/
                         (c->under->faceup?1:2))
                      :c->pile->pos();
    c->AdjustPositions(p,c->pile->delta);
}
void Pile::mouseReleaseEvent(QMouseEvent *ev)
{
    OnClickEvent(NULL);
}
/*




left blank intentionally





*/
PileField::PileField(int x, int y, int dx, int dy, QWidget *parent):
    Pile(x, y, dx, dy, parent)
{}
Rule* PileField::DragRule(int i)
    {return dragRules[i];}
void PileField::DragRule(int i, Rule *r)
{dragRules[i]=r;}
Rule*PileField::DropRule(int i)
{return dropRules[i];}
void PileField::DropRule(int i, Rule *r)
{dropRules[i]=r;}
void PileField::OnClickEvent(Card *c)
{game->OnFieldClick(c);}
void PileField::mouseDoubleClickEvent(Card *c)
{game->OnFieldDoubleClick(c);}

PilePlayOff::PilePlayOff(int x, int y, int dx, int dy,
                         QWidget *parent):
    Pile(x,y,dx,dy,parent)
{}
Rule* PilePlayOff::DragRule(int i)
    {return dragRules[i];}
void PilePlayOff::DragRule(int i, Rule *r)
{dragRules[i]=r;}
Rule*PilePlayOff::DropRule(int i)
{return dropRules[i];}
void PilePlayOff::DropRule(int i, Rule *r)
{dropRules[i]=r;}


PileDeal::PileDeal(int x, int y, int dx, int dy,
                   QWidget *parent):
    Pile(x,y,dx,dy,parent)
{}
Rule* PileDeal::DragRule(int i)
    {return dragRules[i];}
void PileDeal::DragRule(int i, Rule *r)
{dragRules[i]=r;}
Rule*PileDeal::DropRule(int i)
{return dropRules[i];}
void PileDeal::DropRule(int i, Rule *r)
{dropRules[i]=r;}
void PileDeal::OnClickEvent(Card *c)
{game->OnDealClick(c);}

PileDealt::PileDealt(int x, int y, int dx, int dy,
                     QWidget *parent):
    Pile(x,y,dx,dy,parent)
{}
Rule* PileDealt::DragRule(int i)
    {return dragRules[i];}
void PileDealt::DragRule(int i, Rule *r)
{dragRules[i]=r;}
Rule*PileDealt::DropRule(int i)
{return dropRules[i];}
void PileDealt::DropRule(int i, Rule *r)
{dropRules[i]=r;}
void PileDealt::OnClickEvent(Card *c)
{game->OnDealtClick(c);}

PileFreeCell::PileFreeCell(int x, int y, int dx, int dy,
                           QWidget *parent):
    Pile(x,y,dx,dy,parent)
{}
Rule* PileFreeCell::DragRule(int i)
    {return dragRules[i];}
void PileFreeCell::DragRule(int i, Rule *r)
{dragRules[i]=r;}
Rule*PileFreeCell::DropRule(int i)
{return dropRules[i];}
void PileFreeCell::DropRule(int i, Rule *r)
{dropRules[i]=r;}
void PileFreeCell::OnClickEvent(Card *c)
{
    game->OnFreeCellClick(c);
}

