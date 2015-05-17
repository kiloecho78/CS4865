#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QTime>

float scale = 2.0;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    t.start();
    diceSet[0] = new Die(ui->die1);
    diceSet[0]->setPos(0);
    diceSet[1] = new Die(ui->die2);
    diceSet[1]->setPos(1);
    diceSet[2] = new Die(ui->die3);
    diceSet[2]->setPos(2);
    diceSet[3] = new Die(ui->die4);
    diceSet[3]->setPos(3);
    diceSet[4] = new Die(ui->die5);
    diceSet[4]->setPos(4);


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

void GameWindow::sortDice()
{
    for (int k = 1; k < 5; k++){
        Die *x = diceSet[k];
        int i;
        for(i = k-1; (i>=0) && (x->value<diceSet[i]->value); i--)
            diceSet[i+1] = diceSet[i];
        diceSet[i+1] = x;
    }
}

void GameWindow::showDice()
{
    ui->dice1->setText(QString::number(diceSet[0]->value));
    ui->dice2->setText(QString::number(diceSet[1]->value));
    ui->dice3->setText(QString::number(diceSet[2]->value));
    ui->dice4->setText(QString::number(diceSet[3]->value));
    ui->dice5->setText(QString::number(diceSet[4]->value));
}

void GameWindow::on_endTurn_clicked()
{
    diceSet[0]->value = ui->dice1->text().toInt();
    diceSet[1]->value = ui->dice2->text().toInt();
    diceSet[2]->value = ui->dice3->text().toInt();
    diceSet[3]->value = ui->dice4->text().toInt();
    diceSet[4]->value = ui->dice5->text().toInt();
    sortDice();
    showDice();

}


void GameWindow::on_rollButton_clicked()
{
    qsrand(t.elapsed());
    for(int i = 0; i<5; i++)
        diceSet[i]->value = (qrand() % 6)+1;
    showDice();
}
