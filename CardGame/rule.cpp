#include "rule.h"
#include "pile.h"
#include "card.h"
#include "gameboard.h"


extern gameboard *MainApp;
extern Game *game;

bool RuleBaseNone::
Enforce(Pile *p, Card *c)
{
    return false;
}







bool RuleBaseAce::
Enforce(Pile *p, Card *c)
{
    return !p->Empty() || c->Pip() == ACE;
}

bool RuleBaseKing::
Enforce(Pile *p, Card *c)
{
    return !p->Empty()||c->Pip()==KING;
}

bool RuleNoStack::
Enforce(Pile *p, Card *c)
{
    return p->Empty() && !c->Over();
}

bool RuleStackSameSuit::
Enforce(Pile *p, Card *c)
{
    return p->Empty() || c->Suit() == p->Top()->Suit();
}

bool RuleStackAlternateColor::
Enforce(Pile *p, Card *c)
{
    return p->Empty() || c->Color() != p->Top()->Color();
}

bool RuleStackMinusOne::
Enforce(Pile *p, Card *c)
{
    return p->Empty() || p->Top()->Pip();
}

bool RuleStackPlusOne::
Enforce(Pile *p, Card *c)
{
    return p->Empty() || c->Pip() - p->Top()->Pip() == 1;
}

bool RuleStackAny::
Enforce(Pile *p, Card *c)
{
    return true;
}

bool RuleStackOneAtATime::
Enforce(Pile *p, Card *c)
{
    return c->Over() == NULL;
}

bool RuleStack13::
Enforce(Pile *p, Card *c)
{
    Card *temp = c;
    bool ok = true;
    int val = c->Pip();
    suits s = c->Suit();
    while ( ok &&
            (ok = (temp->Pip()==val &&
                   temp->Suit() == s))
            && val < KING)
    {
        val = (val + 1);
        temp = temp->Under();
        ok = temp;
    }
    return ok;
}

bool RuleStackLengthLimited::
Enforce(Pile *p, Card *c)
{
    int cs = c->StackSize();
//    int fm = game->FreeMoves();
//    fm>>= p->Empty()?1:0;
    return cs <= 0;//fm;
}

bool RuleMoveSameSuit::
Enforce(Pile *p, Card *c)
{
    bool ok = true;
    while(ok && c->Over())
    {
        ok = c->Suit() == c->Over()->Suit();
        c = c->Over();
    }
    return ok;
}

bool RuleMoveAltColor::Enforce(Pile *p, Card *c)
{
    bool ok = true;
    while(ok && c->Over())
    {
        ok = c->Color() != c->Over()->Color();
        c = c->Over();
    }
    return ok;
}

bool RuleMoveSeqDecreasing::Enforce(Pile *p, Card *c)
{
    bool ok = true;
    while (ok && c->Over())
    {
        ok = 1 == c->Pip() - c->Over()->Pip();
        c = c->Over();
    }
    return ok;
}


bool RuleMoveSeqIncreasing::Enforce(Pile *p, Card *c)
{
    bool ok = true;
    while(ok && c->Over())
    {
        ok= 1 == c->Over()->Pip()-c->Pip();
        c = c->Over();
    }
    return ok;
}


bool RuleMoveLenghtLimited::Enforce(Pile *p, Card *c)
{
    return c->StackSize() <= game->FreeMoves();
}


bool RuleMoveNone::Enforce(Pile *p, Card *c)
{
    return false;
}


bool RuleMoveOneAtATime::Enforce(Pile *p, Card *c)
{
    return !c->Over();
}
