#include "gamewindow.h"
#include "ui_gamewindow.h"

float scale = 2.0;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    for(int i = 0; i<5; i++)
    {
        diceSet[i] = new Die();
        diceSet[i]->setPos(i);
    }

}

void GameWindow::resizeEvent(QResizeEvent *event)
{
    /*scale = qMin(width()/360.0, height()/300.0);
    ui->die1->setGeometry(0,0,scale*100, scale*100);
    ui->die2->setGeometry(0,0,scale*100, scale*100);
    ui->die3->setGeometry(0,0,scale*100, scale*100);
    ui->die4->setGeometry(0,0,scale*100, scale*100);
    ui->die5->setGeometry(0,0,scale*100, scale*100);*/
}

GameWindow::~GameWindow()
{
    delete ui;
}
