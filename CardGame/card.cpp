
#include "card.h"
#include "pile.h"
#include <QMouseEvent>
#include "gameboard.h"
#include "game.h"
#include <QtGlobal>


QImage Card::faces[53]; // 0 is ACE of CLUBS; 51 is KING of SPADES; 52 is back of cards
bool Card::initialized = false;//true if faces is initialized
QPoint Card::mouseDownOffset;//initialized on mouse down event
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
    value = suit*13 + pip;
    color = static_cast<cardColors>((suit>1)^(suit&1));

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    Faceup(faceup);
}

QSize Card::sizeHint() const
{
    return QSize(71,96);
}
//Used for dealing
void Card::Move(Pile* to, bool expose)
{
    to->AcceptCards(this, expose, false);
}

//Called by main GameBoard Constructor to initialize all card pictures in
//static array
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
    faces[n]=QImage(":/cards/zCardBack.bmp");
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
//---
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
        //the mouse has moved more than 4 pixels since
        moving = true;
    if (moving)
        AdjustPositions(point, pile?pile->Delta():QPoint(0, 10));
}

void Card::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->buttons())return;
    if(popUpCard)
    {
        popUpCard->move(popUpPos); //restore card position
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

void Card::mouseDoubleClickEvent(QMouseEvent *)
{

}

Card* Card::AdjustPositions(QPoint newPos, QPoint delta)
{
    return this;
}

int Card::StackSize()
// fix this
{
    return 0;
}
