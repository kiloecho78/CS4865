#include "die.h"
#include <QTGui>
#include <QWidget>

extern float scale;
QColor dieEdgeColor(0,0,0);
QColor dieCenterColor(255,255,255);
QColor dieHeldColor(219, 255, 255);

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

void Die::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    resize(50*scale, 50*scale);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(dieEdgeColor);
    if(this->held == true)
    {
        p.setBrush(dieHeldColor);
    }
    else
        p.setBrush(dieCenterColor);
    p.scale(scale,scale);
    p.drawRect(0,0,50,50);
    p.setBrush(dieEdgeColor);
    int face = this->value;
    switch(face)
    {
    case 1:
        p.drawEllipse(QPointF(25,25), 4, 4);
        break;
    case 2:
        p.drawEllipse(QPointF(12,12), 4, 4);
        p.drawEllipse(QPointF(37,37), 4, 4);
        break;
    case 3:
        p.drawEllipse(QPointF(12,12), 4, 4);
        p.drawEllipse(QPointF(25,25), 4, 4);
        p.drawEllipse(QPointF(37,37), 4, 4);
        break;
    case 4:
        p.drawEllipse(QPointF(12,12), 4, 4);
        p.drawEllipse(QPointF(12,37), 4, 4);
        p.drawEllipse(QPointF(37,12), 4, 4);
        p.drawEllipse(QPointF(37,37), 4, 4);
        break;
    case 5:
        p.drawEllipse(QPointF(12,12), 4, 4);
        p.drawEllipse(QPointF(12,37), 4, 4);
        p.drawEllipse(QPointF(25,25), 4, 4);
        p.drawEllipse(QPointF(37,12), 4, 4);
        p.drawEllipse(QPointF(37,37), 4, 4);
        break;
    case 6:
        p.drawEllipse(QPointF(12,12), 4, 4);
        p.drawEllipse(QPointF(12,25), 4, 4);
        p.drawEllipse(QPointF(12,37), 4, 4);
        p.drawEllipse(QPointF(37,12), 4, 4);
        p.drawEllipse(QPointF(37,25), 4, 4);
        p.drawEllipse(QPointF(37,37), 4, 4);
        break;
    default:
        break;
    }
}

