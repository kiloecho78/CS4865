#include "die.h"
#include <QTGui>
#include <QWidget>

extern float scale;
QColor dieEdgeColor(0,0,0);
QColor dieCenterColor(255,255,255);

Die::Die(QWidget *parent):QLabel(parent)
{
    show();
}

Die::~Die()
{

}

void Die::mouseReleaseEvent(QMouseEvent *ev)
{

}

void Die::setPos(int p)
{
    pos = p;
}

void Die::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    resize(50*scale, 50*scale);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(dieEdgeColor);
    p.setBrush(dieCenterColor);
    p.scale(scale,scale);
    //const int top = 204;
    p.drawRect(0,0,50,50);
    p.setBrush(dieEdgeColor);
    p.drawEllipse(QPointF(25,25), 5, 5);
}

