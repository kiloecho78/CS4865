#ifndef CARDMOVE_H
#define CARDMOVE_H
#include <QStack>

class Pile;
class Card;
class Cardmove
{
    Card *card;
    Pile *from;
    Pile *to;
    int count;//:16;doesn't work on my machines
    bool wasFaceUp;//:16; doesn't work on my machines
    static QStack<Cardmove*> undostack;
public:
    Cardmove(Card *c, Pile *fr, Pile *t);
    Cardmove(int n);
    static void UndoMove();
    static void Clear();
};

#endif // CARDMOVE_H
