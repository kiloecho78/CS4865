#ifndef CARD_H
#define CARD_H
#include <QWidget>
#include <QLabel>
#include <QImage>

enum cardColors {BLACK, RED};
enum pips {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, SUIT_SIZE};
enum suits {CLUBS, DIAMONDS, HEARTS, SPADES};
class Pile;

class Card : public QLabel
{
    Q_OBJECT
private:
    static QImage faces[53];
    static bool initialized;
    int value;
    Card *under;
    Card *over;
    Pile *pile;

    cardColors color;
    pips pip;
    suits suit;
    bool faceup;
    bool moving;
    bool okToDrag;

    bool hasMouseDown;
    static QPoint mouseDownOffset;
    static QPoint startDragPos;
    static Qt::MouseButtons buttonDown;
    static QPoint popUpPos;
    static Card* popUpCard;

public:
    Card(int v, QWidget *parent =0);
    Card(pips p, suits s, QWidget *parent =0);
    suits Suit(){return suit;}
    pips Pip(){return pip;}
    cardColors Color(){return color;}
    Pile* Pilep(){return pile;}
    Card* Over(){return over;}
    Card* Under(){return under;}
    int StackSize();
    bool Faceup(){return faceup;}
    void Faceup(bool f);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *);
    void Move(Pile* to, bool expose =true);
    Card* AdjustPositions(QPoint newPos, QPoint delta);
    void AlignWithPile();
    static void Initialize();
    void Flip();
    QSize sizeHint() const;
    void Playoff();
    friend class Pile;
    static void SetBacks(int x);
};
void Shuffle(Card* Deck[], int n);

#endif //CARD_H

