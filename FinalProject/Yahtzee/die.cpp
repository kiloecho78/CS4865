#include "die.h"
#include <QTGui>
#include <QWidget>

extern float scale;
QColor dieEdgeColor(0,0,0);
QColor dieCenterColor(255,255,255);
QColor dieHeldColor(219, 255, 255);

Die::Die(QWidget *parent):QPushButton(parent)
{
    show();
}

Die::~Die()
{

}

void Die::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    resize(70*scale, 70*scale);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(dieEdgeColor);
    if(this->held == true)
    {
        p.setBrush(dieHeldColor);
    }
    else
        p.setBrush(dieCenterColor);
    p.scale(scale,scale);
    p.drawRect(0,0,70,70);
    p.setBrush(dieEdgeColor);
    int face = this->value;
    switch(face)
    {
    case 1:
        p.drawEllipse(QPointF(35,35), 6, 6);
        break;
    case 2:
        p.drawEllipse(QPointF(17,17), 6, 6);
        p.drawEllipse(QPointF(52,52), 6, 6);
        break;
    case 3:
        p.drawEllipse(QPointF(17,17), 6, 6);
        p.drawEllipse(QPointF(35,35), 6, 6);
        p.drawEllipse(QPointF(52,52), 6, 6);
        break;
    case 4:
        p.drawEllipse(QPointF(17,17), 6, 6);
        p.drawEllipse(QPointF(17,52), 6, 6);
        p.drawEllipse(QPointF(52,17), 6, 6);
        p.drawEllipse(QPointF(52,52), 6, 6);
        break;
    case 5:
        p.drawEllipse(QPointF(17,17), 6, 6);
        p.drawEllipse(QPointF(17,52), 6, 6);
        p.drawEllipse(QPointF(35,35), 6, 6);
        p.drawEllipse(QPointF(52,17), 6, 6);
        p.drawEllipse(QPointF(52,52), 6, 6);
        break;
    case 6:
        p.drawEllipse(QPointF(17,17), 6, 6);
        p.drawEllipse(QPointF(17,35), 6, 6);
        p.drawEllipse(QPointF(17,52), 6, 6);
        p.drawEllipse(QPointF(52,17), 6, 6);
        p.drawEllipse(QPointF(52,35), 6, 6);
        p.drawEllipse(QPointF(52,52), 6, 6);
        break;
    default:
        p.setBrush(dieCenterColor);
        p.setPen(dieCenterColor);
        p.drawEllipse(QPointF(17,17), 6, 6);
        p.drawEllipse(QPointF(17,35), 6, 6);
        p.drawEllipse(QPointF(17,52), 6, 6);
        p.drawEllipse(QPointF(52,17), 6, 6);
        p.drawEllipse(QPointF(52,35), 6, 6);
        p.drawEllipse(QPointF(52,52), 6, 6);
        p.drawEllipse(QPointF(35,35), 6, 6);
        break;
    }
}

