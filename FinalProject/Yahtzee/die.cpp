#include "die.h"
#include <QTGui>
#include <QWidget>

extern float scale;
QColor dieEdgeColor(0,0,0); //black
QColor dieCenterColor(255,255,255);//white
QColor dieHeldColor(219, 255, 255);//light blue

Die::Die(QWidget *parent):QPushButton(parent)
{
    show();
}
// Function to draw the dice pips on the face of the buttons.
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
    p.drawRoundedRect(0, 0, 65, 65, 10, 10);
    p.setBrush(dieEdgeColor);
    int face = this->value;
    switch(face)
    {
    case 1:
        p.drawEllipse(QPointF(33,33), 6, 6);
        break;
    case 2:
        p.drawEllipse(QPointF(15,15), 6, 6);
        p.drawEllipse(QPointF(50,50), 6, 6);
        break;
    case 3:
        p.drawEllipse(QPointF(15,15), 6, 6);
        p.drawEllipse(QPointF(33,33), 6, 6);
        p.drawEllipse(QPointF(50,50), 6, 6);
        break;
    case 4:
        p.drawEllipse(QPointF(15,15), 6, 6);
        p.drawEllipse(QPointF(15,50), 6, 6);
        p.drawEllipse(QPointF(50,15), 6, 6);
        p.drawEllipse(QPointF(50,50), 6, 6);
        break;
    case 5:
        p.drawEllipse(QPointF(15,15), 6, 6);
        p.drawEllipse(QPointF(15,50), 6, 6);
        p.drawEllipse(QPointF(33,33), 6, 6);
        p.drawEllipse(QPointF(50,15), 6, 6);
        p.drawEllipse(QPointF(50,50), 6, 6);
        break;
    case 6:
        p.drawEllipse(QPointF(15,15), 6, 6);
        p.drawEllipse(QPointF(15,33), 6, 6);
        p.drawEllipse(QPointF(15,50), 6, 6);
        p.drawEllipse(QPointF(50,15), 6, 6);
        p.drawEllipse(QPointF(50,33), 6, 6);
        p.drawEllipse(QPointF(50,50), 6, 6);
        break;
    default:
        p.setBrush(dieCenterColor);
        p.setPen(dieCenterColor);
        p.drawEllipse(QPointF(15,15), 6, 6);
        p.drawEllipse(QPointF(15,33), 6, 6);
        p.drawEllipse(QPointF(15,50), 6, 6);
        p.drawEllipse(QPointF(50,15), 6, 6);
        p.drawEllipse(QPointF(50,33), 6, 6);
        p.drawEllipse(QPointF(50,50), 6, 6);
        p.drawEllipse(QPointF(33,33), 6, 6);
        break;
    }
}

