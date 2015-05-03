#ifndef PILE_H
#define PILE_H
#include <QLabel>
#include <QMouseEvent>
#include "rule.h"
#include "game.h"
class Card;


const int DRAGLAST = 6;
const int DROPLAST = 6;
enum pileType{PLAYOFF, DEAL, DEALT, FIELD, FREE_CELL};

class Pile:public QLabel
{
    QPoint delta;

    Card *top;
    Card *bottom;
    int rulesSet;
    //missing something here

public:
    Pile(int x, int y, int dx, int dy, QWidget *parent);
    ~Pile();

    Card *Top(){return top;}
    Card *Bottom(){return bottom;}
    void AcceptCards(Card *c, bool expose=true, bool record=true);
    void ReleaseCards(Card *c, bool expose=true);
    QPoint Delta(){return delta;}

    bool Empty(){return !bottom;}

    bool CanBeDragged(Card * c);//checks relavent rules for this pile
    bool CanBeDropped(Card * c);//checks relavent rules for this pile
    void FindClosestDrop(Card *c);



    void Deal(QMouseEvent *ev);
    void AddDropRules(int n ...);
    void AddDragRules(int n ...);

    virtual Rule* DragRule(int i)=0;
    virtual void DragRule(int i, Rule* r)=0;
    virtual Rule* DropRule(int i)=0;
    virtual void DropRule(int i, Rule* r)=0;
    virtual pileType Type()=0;

    void mouseReleaseEvent(QMouseEvent *ev);
    virtual void OnClickEvent(Card *c){}
    virtual void mouseDoubleClickEvent(Card *c){}
/*



left blank



*/
};



class PileDeal:public Pile
{
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    PileDeal(int x, int y, int dx, int dy, QWidget *parent);
    Rule* DragRule(int i);
    void DragRule(int i, Rule* r);
    Rule* DropRule(int i);
    void DropRule(int i, Rule* r);
    void OnClickEvent(Card* c);
    pileType Type(){return DEAL;}

};

class PilePlayOff:public Pile
{
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    PilePlayOff(int x, int y, int dx, int dy, QWidget *parent);
    Rule* DragRule(int i);
    void DragRule(int i, Rule* r);
    Rule* DropRule(int i);
    void DropRule(int i, Rule* r);
    pileType Type(){return PLAYOFF;}
};

class PileField:public Pile
{
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    PileField(int x, int y, int dx, int dy, QWidget *parent);
    Rule* DragRule(int i);
    void DragRule(int i, Rule* r);
    Rule* DropRule(int i);
    void DropRule(int i, Rule* r);
    void OnClickEvent(Card* c);
    void mouseDoubleClickEvent(Card *c);
    pileType Type(){return FIELD;}
};

class PileFreeCell:public Pile
{
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    PileFreeCell(int x, int y, int dx, int dy, QWidget *parent);
    Rule* DragRule(int i);
    void DragRule(int i, Rule* r);
    Rule* DropRule(int i);
    void DropRule(int i, Rule* r);
    void OnClickEvent(Card* c);
//    void mouseDoubleClickEvent(Card *c);
    pileType Type(){return FREE_CELL;}
};

class PileDealt:public Pile
{
    static Rule *dragRules[DRAGLAST];
    static Rule *dropRules[DROPLAST];
public:
    PileDealt(int x, int y, int dx, int dy, QWidget *parent);
    Rule* DragRule(int i);
    void DragRule(int i, Rule* r);
    Rule* DropRule(int i);
    void DropRule(int i, Rule* r);
    void OnClickEvent(Card* c);
//    void mouseDoubleClickEvent(Card *c);
    pileType Type(){return DEALT;}
};
#endif // PILE_H
