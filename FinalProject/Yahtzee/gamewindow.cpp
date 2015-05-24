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
    die1->setFlat(true);
    ui->diceGridLayout->addWidget(die1,1,0,Qt::AlignCenter);

    die2 = new QPushButton();
    die2->setMinimumSize(50,50);
    die2->setMaximumSize(50,50);
    die2->setFlat(true);
    ui->diceGridLayout->addWidget(die2,1,1,Qt::AlignCenter);
    die3 = new QPushButton();
    die3->setMinimumSize(50,50);
    die3->setMaximumSize(50,50);
    die3->setFlat(true);
    ui->diceGridLayout->addWidget(die3,1,2,Qt::AlignCenter);
    die4 = new QPushButton();
    die4->setMinimumSize(50,50);
    die4->setMaximumSize(50,50);
    die4->setFlat(true);
    ui->diceGridLayout->addWidget(die4,1,3,Qt::AlignCenter);
    die5 = new QPushButton();
    die5->setMinimumSize(50,50);
    die5->setMaximumSize(50,50);
    die5->setFlat(true);
    ui->diceGridLayout->addWidget(die5,1,4,Qt::AlignCenter);
    diceSet[0] = new Die(die1);
    diceSet[1] = new Die(die2);
    diceSet[2] = new Die(die3);
    diceSet[3] = new Die(die4);
    diceSet[4] = new Die(die5);
    dice1 = new QLineEdit();
    dice2 = new QLineEdit();
    dice3 = new QLineEdit();
    dice4 = new QLineEdit();
    dice5 = new QLineEdit();
    ui->diceGridLayout->addWidget(dice1,3,0,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice2,3,1,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice3,3,2,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice4,3,3,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(dice5,3,4,Qt::AlignCenter);
    rollButton = new QPushButton();
    rollButton->setText("Roll");
    endTurn = new QPushButton();
    endTurn->setText("Score");
    connect(rollButton,SIGNAL(clicked()),this,SLOT(on_rollButton_clicked()));
    connect(endTurn,SIGNAL(clicked()),this,SLOT(on_endTurn_clicked()));
    ui->diceGridLayout->addWidget(rollButton,2,2,Qt::AlignCenter);
    ui->diceGridLayout->addWidget(endTurn,2,4,Qt::AlignCenter);
    gameColHeader = new QLabel(QString("Yahtzee!"));
    QFont f("Arial", 28, QFont::Bold);
    gameColHeader->setFont(f);
    gameColHeader->setFrameShape(QFrame::Box);
    gameColHeader->setLineWidth(2);
    ui->scorecardLayout->addWidget(gameColHeader,0,0);
    ui->scorecardLayout->addWidget(playerNameColHeader = new QLabel(QString("Amy")),0,2);
    ui->scorecardLayout->addWidget(one = new QLabel(QString("Aces")),1,0);
    ui->scorecardLayout->addWidget(two = new QLabel(QString("Twos")),2,0);
    ui->scorecardLayout->addWidget(three = new QLabel(QString("Threes")),3,0);
    ui->scorecardLayout->addWidget(four = new QLabel(QString("Fours")),4,0);
    ui->scorecardLayout->addWidget(five = new QLabel(QString("Fives")),5,0);
    ui->scorecardLayout->addWidget(six = new QLabel(QString("Sixes")),6,0);
    ui->scorecardLayout->addWidget(topSubTotal = new QLabel(QString("TOTAL SCORE")),7,0);
    ui->scorecardLayout->addWidget(bonus = new QLabel(QString("BONUS if total score is 63 or more")),8,0);
    ui->scorecardLayout->addWidget(topGrandTotal = new QLabel(QString("TOTAL of Upper Section")),9,0);
    ui->scorecardLayout->addWidget(toak = new QLabel(QString("Three of a Kind")),10,0);
    ui->scorecardLayout->addWidget(foak = new QLabel(QString("Four of a Kind")),11,0);
    ui->scorecardLayout->addWidget(fh = new QLabel(QString("Full House")),12,0);
    ui->scorecardLayout->addWidget(sms  = new QLabel(QString("Small Straight")),13,0);
    ui->scorecardLayout->addWidget(lgs = new QLabel(QString("Large Straight")),14,0);
    ui->scorecardLayout->addWidget(chance = new QLabel(QString("Chance")),15,0);
    ui->scorecardLayout->addWidget(yahtzee = new QLabel(QString("YAHTZEE")),16,0);
    ui->scorecardLayout->addWidget(bottomSubTotal = new QLabel(QString("TOTAL of Lower Section")),17,0);
    ui->scorecardLayout->addWidget(topGrandTotal2 = new QLabel(QString("TOTAL of Upper Section")),18,0);
    ui->scorecardLayout->addWidget(grandTotal = new QLabel(QString("GRAND TOTAL")),19,0);
    ui->scorecardLayout->addWidget(oneScore = new QPushButton(),1,2);
    ui->scorecardLayout->addWidget(twoScore = new QPushButton(),2,2);
    ui->scorecardLayout->addWidget(threeScore = new QPushButton(),3,2);
    ui->scorecardLayout->addWidget(fourScore = new QPushButton(),4,2);
    ui->scorecardLayout->addWidget(fiveScore = new QPushButton(),5,2);
    ui->scorecardLayout->addWidget(sixScore = new QPushButton(),6,2);
    ui->scorecardLayout->addWidget(topSubTotalScore = new QLabel(),7,2);
    ui->scorecardLayout->addWidget(bonusScore  = new QLabel(),8,2);
    ui->scorecardLayout->addWidget(topGrandTotalScore = new QLabel(),9,2);
    ui->scorecardLayout->addWidget(threeOfAKindScore = new QPushButton(),10,2);
    ui->scorecardLayout->addWidget(fourOfAKindScore = new QPushButton(),11,2);
    ui->scorecardLayout->addWidget(fullHouseScore = new QPushButton(),12,2);
    ui->scorecardLayout->addWidget(smStraightScore = new QPushButton(),13,2);
    ui->scorecardLayout->addWidget(lgStraightScore = new QPushButton(),14,2);
    ui->scorecardLayout->addWidget(chanceScore = new QPushButton(),15,2);
    ui->scorecardLayout->addWidget(yahtzeeScore = new QPushButton(),16,2);
    ui->scorecardLayout->addWidget(bottomSubTotalScore = new QLabel(),17,2);
    ui->scorecardLayout->addWidget(topGrandTotal2Score = new QLabel(),18,2);
    ui->scorecardLayout->addWidget(grandTotalScore = new QLabel(),19,2);
    one->setFrameShape(QFrame::Box);
    one->setLineWidth(1);
    two->setFrameShape(QFrame::Box);
    two->setLineWidth(1);
    three->setFrameShape(QFrame::Box);
    three->setLineWidth(1);
    four->setFrameShape(QFrame::Box);
    four->setLineWidth(1);
    five->setFrameShape(QFrame::Box);
    five->setLineWidth(1);
    six->setFrameShape(QFrame::Box);
    six->setLineWidth(1);
    toak->setFrameShape(QFrame::Box);
    toak->setLineWidth(1);
    foak->setFrameShape(QFrame::Box);
    foak->setLineWidth(1);
    sms->setFrameShape(QFrame::Box);
    sms->setLineWidth(1);
    lgs->setFrameShape(QFrame::Box);
    lgs->setLineWidth(1);
    chance->setFrameShape(QFrame::Box);
    chance->setLineWidth(1);
    yahtzee->setFrameShape(QFrame::Box);
    yahtzee->setLineWidth(1);
    topSubTotal->setFrameShape(QFrame::Box);
    topSubTotal->setLineWidth(1);
    bonus->setFrameShape(QFrame::Box);
    bonus->setLineWidth(1);
    topGrandTotal->setFrameShape(QFrame::Box);
    topGrandTotal->setLineWidth(1);
    bottomSubTotal->setFrameShape(QFrame::Box);
    bottomSubTotal->setLineWidth(1);
    topGrandTotal2->setFrameShape(QFrame::Box);
    topGrandTotal2->setLineWidth(1);
    grandTotal->setFrameShape(QFrame::Box);
    grandTotal->setLineWidth(1);
    topSubTotalScore->setFrameShape(QFrame::Box);
    topSubTotalScore->setLineWidth(1);
    bonusScore->setFrameShape(QFrame::Box);
    bonusScore->setLineWidth(1);
    topGrandTotalScore->setFrameShape(QFrame::Box);
    topGrandTotalScore->setLineWidth(1);
    bottomSubTotalScore->setFrameShape(QFrame::Box);
    bottomSubTotalScore->setLineWidth(1);
    topGrandTotal2Score->setFrameShape(QFrame::Box);
    topGrandTotal2Score->setLineWidth(1);
    grandTotalScore->setFrameShape(QFrame::Box);
    grandTotalScore->setLineWidth(1);
    fh->setFrameShape(QFrame::Box);
    fh->setLineWidth(1);
    setUpScoreButtonArray();
    setUpScoreLabelArray();
    connect(oneScore,SIGNAL(clicked()),this,SLOT(on_oneScore_clicked()));
    connect(twoScore,SIGNAL(clicked()),this,SLOT(on_twoScore_clicked()));
    connect(threeScore,SIGNAL(clicked()),this,SLOT(on_threeScore_clicked()));
    connect(fourScore,SIGNAL(clicked()),this,SLOT(on_fourScore_clicked()));
    connect(fiveScore,SIGNAL(clicked()),this,SLOT(on_fiveScore_clicked()));
    connect(sixScore,SIGNAL(clicked()),this,SLOT(on_sixScore_clicked()));
    connect(threeOfAKindScore,SIGNAL(clicked()),this,SLOT(on_toakScore_clicked()));
    connect(fourOfAKindScore,SIGNAL(clicked()),this,SLOT(on_foakScore_clicked()));
    connect(fullHouseScore,SIGNAL(clicked()),this,SLOT(on_fhScore_clicked()));
    connect(smStraightScore,SIGNAL(clicked()),this,SLOT(on_smsScore_clicked()));
    connect(lgStraightScore,SIGNAL(clicked()),this,SLOT(on_lgsScore_clicked()));
    connect(chanceScore,SIGNAL(clicked()),this,SLOT(on_chanceScore_clicked()));
    connect(yahtzeeScore,SIGNAL(clicked()),this,SLOT(on_yahtzeeScore_clicked()));


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

void GameWindow::setUpScoreButtonArray()
{
    scoreButtonSet[0]= oneScore;
    scoreButtonSet[1]= twoScore;
    scoreButtonSet[2]= threeScore;
    scoreButtonSet[3]= fourScore;
    scoreButtonSet[4]= fiveScore;
    scoreButtonSet[5]= sixScore;
    scoreButtonSet[6]= threeOfAKindScore;
    scoreButtonSet[7]= fourOfAKindScore;
    scoreButtonSet[8]= fullHouseScore;
    scoreButtonSet[9]= smStraightScore;
    scoreButtonSet[10]= lgStraightScore;
    scoreButtonSet[11]= chanceScore;
    scoreButtonSet[12]= yahtzeeScore;
}

void GameWindow::setUpScoreLabelArray()
{
    scoreLabelSet[0]= topSubTotalScore;
    scoreLabelSet[1]= bonusScore;
    scoreLabelSet[2]= topGrandTotalScore;
    scoreLabelSet[3]= bottomSubTotalScore;
    scoreLabelSet[4]= topGrandTotal2Score;
    scoreLabelSet[5]= grandTotalScore;
}

void GameWindow::on_oneScore_clicked()
{
    int score = 0;
    oneScoreSet = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value==1)
            score++;
    }
    oneScore->setText(QString::number(score));
}

void GameWindow::on_twoScore_clicked()
{
    int score = 0;
    twoScoreSet = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value==2)
            score+=2;
    }
    twoScore->setText(QString::number(score));
}

void GameWindow::on_threeScore_clicked()
{
    int score = 0;
    threeScoreSet = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 3)
            score+=3;
    }
    threeScore->setText(QString::number(score));
}

void GameWindow::on_fourScore_clicked()
{
    int score = 0;
    fourScoreSet = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 4)
            score+=4;
    }
    fourScore->setText(QString::number(score));
}

void GameWindow::on_fiveScore_clicked()
{
    int score = 0;
    fiveScoreSet = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 5)
            score+=5;
    }
    fiveScore->setText(QString::number(score));
}

void GameWindow::on_sixScore_clicked()
{
    int score = 0;
    sixScoreSet = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 6)
            score+=6;
    }
    sixScore->setText(QString::number(score));
}

void GameWindow::on_toakScore_clicked()
{
    int score = 0;
    threeOfAKindScoreSet = true;
    sortDice();
    if((diceSet[2]->value==diceSet[1]->value==diceSet[0]->value)
            ||(diceSet[2]->value==diceSet[1]->value==diceSet[3]->value)
            ||(diceSet[2]->value==diceSet[3]->value==diceSet[4]->value))
    {
        for(int i = 0; i<5; i++)
        {
            score += diceSet[i]->value;
        }
    }
    threeOfAKindScore->setText(QString::number(score));
}

void GameWindow::on_foakScore_clicked()
{
    int score = 0;
    fourOfAKindScoreSet = true;
    sortDice();
    if((diceSet[3]->value==diceSet[2]->value==diceSet[1]->value==diceSet[0]->value)
            ||(diceSet[4]->value==diceSet[2]->value==diceSet[1]->value==diceSet[3]->value))
    {
        for(int i = 0; i<5; i++)
        {
            score += diceSet[i]->value;
        }
    }
    fourOfAKindScore->setText(QString::number(score));
}

void GameWindow::on_fhScore_clicked()
{
    int score = 0;
    fullHouseScoreSet = true;
    sortDice();
    if(((diceSet[2]->value==diceSet[1]->value==diceSet[0]->value)&&(diceSet[4]->value==diceSet[3]->value))
            ||((diceSet[2]->value==diceSet[3]->value==diceSet[4]->value)&&(diceSet[0]->value==diceSet[1]->value)))
            score = 25;
    fullHouseScore->setText(QString::number(score));

}

void GameWindow::on_smsScore_clicked()
{
    int score = 0;
    smStraightScoreSet = true;
    sortDice();
    if(true)
     {   score = 30;}
     smStraightScore->setText(QString::number(score));
}

void GameWindow::on_lgsScore_clicked()
{
    int score = 0;
    lgStraightScoreSet = true;
    sortDice();
    if((diceSet[0]->value!=diceSet[1]->value)&&
            (diceSet[1]->value!=diceSet[2]->value)&&
            (diceSet[2]->value!=diceSet[3]->value)&&
            (diceSet[3]->value!=diceSet[4]->value))
            score = 40;
    lgStraightScore->setText(QString::number(score));
}

void GameWindow::on_chanceScore_clicked()
{
    int score = 0;
    chanceScoreSet = true;
    for(int i = 0; i<5; i++)
        score+=diceSet[i]->value;
    chanceScore->setText(QString::number(score));
}

void GameWindow::on_yahtzeeScore_clicked()
{
    int score = 0;
    yahtzeeScoreSet = true;
    sortDice();
    if(diceSet[0]->value==diceSet[4]->value)
            score = 50;
    yahtzeeScore->setText(QString::number(score));
}
