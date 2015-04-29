#ifndef CARD_H
#define CARD_H
#include <QWidget>
#include <QLabel>
#include <QImage>


enum cardColors {BLACK, RED};
enum pips {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, SUIT_SIZE};
enum suits {CLUBS, DIAMONDS, HEARTS, SPADES};
class Pile; //forward declaration

class Card : public QLabel
{
    Q_OBJECT
private:
    static QImage faces[53];
    static bool initialized;
    int value; //zero to 51
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
    static QPoint mouseDownOffset; //Distance to add to mouse pos to move
    static QPoint startDragPos;
    static Qt::MouseButtons buttonDown; //at time button pressed, record all values of all buttons
    static QPoint popUpPos; //where it was before popped up, pointer that points to the card that got popped up
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
    int StackSize(); //Has to be measured, if nothing on top of it then stack size = 1
    bool Faceup(){return faceup;}
    void Faceup(bool f);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *);
    void Move(Pile* to, bool expose =true);
    Card* AdjustPositions(QPoint newPos, QPoint delta);
    void AlignWithPile();
    void Animate(QPoint newpos);//not really necessary
    static void Initialize(); //do not require an instance of the object type to be called. initializes the static array of cards
    void Flip();//changes the face-up value of the card
    QSize sizeHint() const;
    void Playoff();//get a card from the field pile to the completion pile (like 2D to AD in klondike)
    friend class Pile; //piles can play with the cards
};
void Shuffle(Card* Deck[], int n);

#endif //CARD_H
//Menu: Game (new->, redeal, playoff, preferences) Edit (undo) Help (rules, about)
