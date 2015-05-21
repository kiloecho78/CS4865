#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QTime>


float scale = 1.0;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    t.start();
    die1 = new QPushButton();
    die1->setMinimumSize(50,50);
    die1->setMaximumSize(50,50);
    die1->setText(QString(""));
    die1->setFlat(true);
    ui->diceGridLayout->addWidget(die1,0,0,Qt::AlignCenter);

    die2 = new QPushButton();
    die2->setMinimumSize(50,50);
    die2->setMaximumSize(50,50);
    die2->setText(QString(""));
    die2->setFlat(true);
    ui->diceGridLayout->addWidget(die2,0,1,Qt::AlignCenter);
    die3 = new QPushButton();
    die3->setMinimumSize(50,50);
    die3->setMaximumSize(50,50);
    die3->setText(QString(""));
    die3->setFlat(true);
    ui->diceGridLayout->addWidget(die3,0,2,Qt::AlignCenter);
    die4 = new QPushButton();
    die4->setMinimumSize(50,50);
    die4->setMaximumSize(50,50);
    die4->setText(QString(""));
    die4->setFlat(true);
    ui->diceGridLayout->addWidget(die4,0,3,Qt::AlignCenter);
    die5 = new QPushButton();
    die5->setMinimumSize(50,50);
    die5->setMaximumSize(50,50);
    die5->setText(QString(""));
    die5->setFlat(true);
    ui->diceGridLayout->addWidget(die5,0,4,Qt::AlignCenter);
    diceSet[0] = new Die(die1);
    diceSet[0]->setPos(0);
    diceSet[1] = new Die(die2);
    diceSet[1]->setPos(1);
    diceSet[2] = new Die(die3);
    diceSet[2]->setPos(2);
    diceSet[3] = new Die(die4);
    diceSet[3]->setPos(3);
    diceSet[4] = new Die(die5);
    diceSet[4]->setPos(4);
    dice1 = new QLineEdit();
    dice2 = new QLineEdit();
    dice3 = new QLineEdit();
    dice4 = new QLineEdit();
    dice5 = new QLineEdit();
    ui->diceGridLayout->addWidget(dice1,2,0,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice2,2,1,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice3,2,2,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice4,2,3,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice5,2,4,Qt::AlignCenter);
    rollButton = new QPushButton();
    endTurn = new QPushButton();
    ui->diceGridLayout->addWidget(rollButton,1,2,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(endTurn,1,4,Qt::AlignCenter);

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
    dice1->setText(QString::number(diceSet[0]->value));
    dice2->setText(QString::number(diceSet[1]->value));
    dice3->setText(QString::number(diceSet[2]->value));
    dice4->setText(QString::number(diceSet[3]->value));
    dice5->setText(QString::number(diceSet[4]->value));
}

void GameWindow::on_endTurn_clicked()
{
    diceSet[0]->value = dice1->text().toInt();
    diceSet[1]->value = dice2->text().toInt();
    diceSet[2]->value = dice3->text().toInt();
    diceSet[3]->value = dice4->text().toInt();
    diceSet[4]->value = dice5->text().toInt();
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
