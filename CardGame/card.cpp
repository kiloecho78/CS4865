#include "card.h"
#include "pile.h"
#include <QMouseEvent>
#include "gameboard.h"
#include "game.h"
#include <QtGlobal>
#include <QString>

QImage Card::faces[53];
bool Card::initialized = false;
QPoint Card::mouseDownOffset;
QPoint Card::startDragPos;
Qt::MouseButtons Card::buttonDown;
QPoint Card::popUpPos;
Card* Card::popUpCard;

extern gameboard *MainApp;
extern Game *game;

Card::Card(int v, QWidget *parent):
    QLabel(parent), value(v), under(0), over(0),pile(0), faceup(false),
    moving(false), hasMouseDown(false)
{
    suit = static_cast<suits>(value / 13);
    pip = static_cast<pips>(value % 13);
    color = static_cast<cardColors>((suit>1)^(suit&1));

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    Faceup(faceup);
}

Card::Card(pips p, suits s, QWidget *parent):
    QLabel(parent), under(0), over(0), pile(0), pip(p), suit(s), faceup(false),
    moving(false), hasMouseDown(false)
{
    value = suit*SUIT_SIZE + pip;
    color = static_cast<cardColors>((suit>1)^(suit&1));

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    Faceup(faceup);
}

QSize Card::sizeHint() const
{return QSize(71,96);}

void Card::Move(Pile* to, bool expose)
{
    to->AcceptCards(this, expose, false);
}

void Card::Initialize()
{
    if(initialized) return;
    initialized = true;
    char suit[]={'c','d','h','s'};
    char pip[]= {'1','2','3','4','5','6','7','8','9','a','b','c','d'};
    QString fname = ":/cards/c1.bmp";
    int n = 0;
    for(int s = CLUBS; s <= SPADES; ++s)
    {
        fname[8]=suit[s];
        for(int p = ACE; p <= KING; ++p)
        {
            fname[9]=pip[p];
            faces[n++]=QImage(fname);
        }
    }

    faces[n]= QImage(":/cards/zCardBack.bmp");
}

void Card::SetBacks(int x)
{
    if(x == 4)
        faces[52]= QImage(":/cards/zCardBackBicycle.bmp");
    else if(x == 1)
        faces[52]= QImage(":/cards/zCardBackCAH.bmp");

    else if(x == 2)
        faces[52]= QImage(":/cards/zCardBackFish.bmp");
    else if(x == 3)
        faces[52]= QImage(":/cards/zCardBackHot.bmp");
    else
        faces[52]= QImage(":/cards/zCardBack.bmp");
    game->ReDeal();
}

void Card::Flip()
{
    Faceup(!faceup);
}

void Card::Faceup(bool f)
{
    faceup = f;
    setPixmap(QPixmap::fromImage(faces[faceup?value:52]));
}

void Shuffle(Card *Deck[], int n)
{
    Card* temp;
    int k;
    while(n>0)
    {
        k = qrand() % n--;
        temp = Deck[k];
        Deck[k] = Deck[n];
        Deck[n] = temp;
        temp->raise();
    }
}

void Card::mousePressEvent(QMouseEvent *ev)
{
    switch (ev->button())
    {
    case Qt::LeftButton:
        startDragPos = pos();
        mouseDownOffset = pos() - ev->globalPos();
        okToDrag = faceup && pile->CanBeDragged(this);
        break;
    case Qt::RightButton:
        popUpPos = pos();
        popUpCard = this;
        move(pos() +QPoint(0,-20));
        break;
    default: ;
    }
}

void Card::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->globalPos() + mouseDownOffset;
    QPoint moved = point - pos();
    if (okToDrag && moved.manhattanLength() > 4)
        moving = true;
    if (moving)
        AdjustPositions(point, pile?pile->Delta():QPoint(0, 10));
}

void Card::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->buttons())return;
    if(popUpCard)
    {
        popUpCard->move(popUpPos);
        popUpCard = NULL;
        return;
    }
    if(moving && pile)
        pile->FindClosestDrop(this);
    else
        if(pile)
        {
            QPoint point = ev->globalPos() + mouseDownOffset;
            QPoint moved = point - pos();
            if (moved.manhattanLength() <= 4)
                pile->OnClickEvent(this);
        }
    moving = false;
    okToDrag = false;
}

Card* Card::AdjustPositions(QPoint newPos, QPoint delta)
{
    Card *c = this;
    Card *top;
    do{
        c->move(newPos);
        c->raise();
        c->show();
        newPos += (delta/(c->faceup?1:2));
        top = c;
        c->pile = pile;
        c = c->over;
    }while(c);
    return top;
}

void Card::AlignWithPile()
{
    move(pile->pos());
}

int Card::StackSize()
{
    int count = 0;
    Card* card = this;
    do
    {
        count++;
        card = card->over;
    }while(card);
    return count;
}

void Card::mouseDoubleClickEvent(QMouseEvent *)
{
    if(pile)
        pile->mouseDoubleClickEvent(this);

}

void Card::Playoff()
{
    game->PlayOff(this);
}

