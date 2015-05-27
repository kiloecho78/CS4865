#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "rulesdialog.h"
#include <QTime>

extern RulesDialog *Rules;
float scale = 1.0;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    t.start();
    player1 = new Player("Keith", 1);
    player2 = new Player("Amy", 2);
    turnOrder.enqueue(player1);
    turnOrder.enqueue(player2);
    diceSet[0] = (die1 = new Die(this));
    die1->setMinimumSize(50,50);
    die1->setMaximumSize(50,50);
//    die1->setFlat(true);
    ui->diceGridLayout->addWidget(die1,1,0,Qt::AlignCenter);
    diceSet[1] = (die2 = new Die(this));
    die2->setMinimumSize(50,50);
    die2->setMaximumSize(50,50);
//    die2->setFlat(true);
    ui->diceGridLayout->addWidget(die2,1,1,Qt::AlignCenter);
    diceSet[2] = (die3 = new Die(this));
    die3->setMinimumSize(50,50);
    die3->setMaximumSize(50,50);
//    die3->setFlat(true);
    ui->diceGridLayout->addWidget(die3,1,2,Qt::AlignCenter);
    diceSet[3] = (die4 = new Die(this));
    die4->setMinimumSize(50,50);
    die4->setMaximumSize(50,50);
//    die4->setFlat(true);
    ui->diceGridLayout->addWidget(die4,1,3,Qt::AlignCenter);
    diceSet[4] = (die5 = new Die(this));
    die5->setMinimumSize(50,50);
    die5->setMaximumSize(50,50);
//    die5->setFlat(true);
    ui->diceGridLayout->addWidget(die5,1,4,Qt::AlignCenter);
    createSet();
    rollButton = new QPushButton();
    rollButton->setText("Roll");
//    endTurn = new QPushButton();
//    endTurn->setText("Score");
    connect(rollButton,SIGNAL(clicked()),this,SLOT(rollButton_clicked()));
//    connect(endTurn,SIGNAL(clicked()),this,SLOT(endTurn_clicked()));
    ui->diceGridLayout->addWidget(rollButton,2,2,Qt::AlignCenter);
//    ui->diceGridLayout->addWidget(endTurn,2,4,Qt::AlignCenter);*/
    gameColHeader = new QLabel(QString("Yahtzee!"));
    QFont f("Arial", 28, QFont::Bold);
    gameColHeader->setFont(f);
    gameColHeader->setFrameShape(QFrame::Box);
    gameColHeader->setLineWidth(2);
    ui->scorecardLayout->addWidget(gameColHeader,0,0);
    ui->scorecardLayout->addWidget(playerNameColHeader = new QLabel(),0,2);
    ui->scorecardLayout->addWidget(one = new QLabel(QString("Aces")),1,0);
    ui->scorecardLayout->addWidget(two = new QLabel(QString("Twos")),2,0);
    ui->scorecardLayout->addWidget(three = new QLabel(QString("Threes")),3,0);
    ui->scorecardLayout->addWidget(four = new QLabel(QString("Fours")),4,0);
    ui->scorecardLayout->addWidget(five = new QLabel(QString("Fives")),5,0);
    ui->scorecardLayout->addWidget(six = new QLabel(QString("Sixes")),6,0);
    ui->scorecardLayout->addWidget(topSubTotal = new QLabel(QString("TOTAL SCORE")),7,0);
    ui->scorecardLayout->addWidget(bonus = new QLabel(QString("BONUS (if total score is 63 or more)")),8,0);
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
    topSubTotalScore->setAlignment(Qt::AlignCenter);
    bonusScore->setFrameShape(QFrame::Box);
    bonusScore->setLineWidth(1);
    bonusScore->setAlignment(Qt::AlignCenter);
    topGrandTotalScore->setFrameShape(QFrame::Box);
    topGrandTotalScore->setLineWidth(1);
    topGrandTotalScore->setAlignment(Qt::AlignCenter);
    bottomSubTotalScore->setFrameShape(QFrame::Box);
    bottomSubTotalScore->setLineWidth(1);
    bottomSubTotalScore->setAlignment(Qt::AlignCenter);
    topGrandTotal2Score->setFrameShape(QFrame::Box);
    topGrandTotal2Score->setLineWidth(1);
    topGrandTotal2Score->setAlignment(Qt::AlignCenter);
    grandTotalScore->setFrameShape(QFrame::Box);
    grandTotalScore->setLineWidth(1);
    grandTotalScore->setAlignment(Qt::AlignCenter);
    fh->setFrameShape(QFrame::Box);
    fh->setLineWidth(1);
    setUpScoreButtonArray();
    setUpScoreLabelArray();
    connect(oneScore,SIGNAL(clicked()),this,SLOT(oneScore_clicked()));
    connect(twoScore,SIGNAL(clicked()),this,SLOT(twoScore_clicked()));
    connect(threeScore,SIGNAL(clicked()),this,SLOT(threeScore_clicked()));
    connect(fourScore,SIGNAL(clicked()),this,SLOT(fourScore_clicked()));
    connect(fiveScore,SIGNAL(clicked()),this,SLOT(fiveScore_clicked()));
    connect(sixScore,SIGNAL(clicked()),this,SLOT(sixScore_clicked()));
    connect(threeOfAKindScore,SIGNAL(clicked()),this,SLOT(toakScore_clicked()));
    connect(fourOfAKindScore,SIGNAL(clicked()),this,SLOT(foakScore_clicked()));
    connect(fullHouseScore,SIGNAL(clicked()),this,SLOT(fhScore_clicked()));
    connect(smStraightScore,SIGNAL(clicked()),this,SLOT(smsScore_clicked()));
    connect(lgStraightScore,SIGNAL(clicked()),this,SLOT(lgsScore_clicked()));
    connect(chanceScore,SIGNAL(clicked()),this,SLOT(chanceScore_clicked()));
    connect(yahtzeeScore,SIGNAL(clicked()),this,SLOT(yahtzeeScore_clicked()));
    connect(die1,SIGNAL(clicked()),this,SLOT(die1_clicked()));
    connect(die2,SIGNAL(clicked()),this,SLOT(die2_clicked()));
    connect(die3,SIGNAL(clicked()),this,SLOT(die3_clicked()));
    connect(die4,SIGNAL(clicked()),this,SLOT(die4_clicked()));
    connect(die5,SIGNAL(clicked()),this,SLOT(die5_clicked()));

    playgame();
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
    for(int i = 0; i<6; i++)
    {
        diceSet[i]->repaint();
    }
}


void GameWindow::rollButton_clicked()
{
    if(currentPlayer->rolls > 0)
    {
        qsrand(t.elapsed());
        for(int i = 0; i<5; i++)
            if(!diceSet[i]->held)
                diceSet[i]->value = (qrand() % 6)+1;
        showDice();
        currentPlayer->rolls--;
    }
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
    for(int i = 0; i<6; i++)
    {
        topScoreSetArray[i] = false;
        bottomScoreSetArray[i] = false;
    }
    bottomScoreSetArray[6]=false;
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

bool GameWindow::goFish(int x)
{
    for(int i = 0; i<5; i++)
        if(diceSet[i]->value==x)
            return true;
    return false;
}

bool GameWindow::checkSmallStraight()
{
    return(goFish(1)&&goFish(2)&&goFish(3)&&goFish(4))||(goFish(2)&&goFish(3)&&goFish(4)&&goFish(5))||(goFish(3)&&goFish(4)&&goFish(5)&&goFish(6));
}

void GameWindow::checkTopComplete()
{
    bool topCompleted = true;
    for(int i = 0; i < 6; i++)
    {
        if(!topScoreSetArray[i])
            topCompleted = false;
    }
    if(topCompleted)
    {
        if(topSubTotalScore->text().toInt()>=63)
        {
            int temp = (topSubTotalScore->text().toInt())+35;
            bonusScore->setText(QString::number(35));
            topGrandTotalScore->setText(QString::number(temp));
            topGrandTotal2Score->setText(QString::number(temp));
        }
        else
        {
            bonusScore->setText(QString::number(0));
            topGrandTotalScore->setText(topSubTotalScore->text());
            topGrandTotal2Score->setText(topSubTotalScore->text());
        }
        sectionsCompleted++;
        finalScore();
    }
}

void GameWindow::checkBottomComplete()
{
    bool botCompleted = true;
    for(int i = 0; i < 7; i++)
    {
        if(!bottomScoreSetArray[i])
            botCompleted = false;
    }
    if(botCompleted)
        sectionsCompleted++;
        finalScore();
}

void GameWindow::finalScore()
{
    if(sectionsCompleted == 2)
    {
        int score = 0;
        score += topGrandTotal2Score->text().toInt();
        score += bottomSubTotalScore->text().toInt();
        grandTotalScore->setText(QString::number(score));
    }
    else
    {
        return;
    }
}

void GameWindow::createSet()
{
    for(int i =0; i<5; i++)
    {
        diceSet[i]->held = false;
        diceSet[i]->setEnabled(true);
    }
}
//-------------------------------------------------------------------------------------------------------------------------
void GameWindow::playgame()
{
        currentPlayer = turnOrder.dequeue();
        currentPlayer->rolls = 3;
        playerNameColHeader->setText(currentPlayer->myname);
        (currentPlayer->myScore.ones==-1)? oneScore->setText(""):oneScore->setText(QString::number(currentPlayer->myScore.ones));
        (currentPlayer->myScore.twos==-1)? twoScore->setText(""):twoScore->setText(QString::number(currentPlayer->myScore.twos));
        (currentPlayer->myScore.threes==-1)? threeScore->setText(""):threeScore->setText(QString::number(currentPlayer->myScore.threes));
        (currentPlayer->myScore.fours==-1)? fourScore->setText(""):fourScore->setText(QString::number(currentPlayer->myScore.fours));
        (currentPlayer->myScore.fives==-1)? fiveScore->setText(""):fiveScore->setText(QString::number(currentPlayer->myScore.fives));
        (currentPlayer->myScore.sixes==-1)? sixScore->setText(""):sixScore->setText(QString::number(currentPlayer->myScore.sixes));
}

void GameWindow::endTurn()
{
    currentPlayer->rolls=0;
    (oneScore->text()=="")? currentPlayer->myScore.ones = -1: currentPlayer->myScore.ones = oneScore->text().toInt();
    (twoScore->text()=="")? currentPlayer->myScore.twos = -1: currentPlayer->myScore.twos = twoScore->text().toInt();
    (threeScore->text()=="")? currentPlayer->myScore.threes = -1: currentPlayer->myScore.threes = threeScore->text().toInt();
    (fourScore->text()=="")? currentPlayer->myScore.fours = -1: currentPlayer->myScore.fours = fourScore->text().toInt();
    (fiveScore->text()=="")? currentPlayer->myScore.fives = -1: currentPlayer->myScore.fives = fiveScore->text().toInt();
    (sixScore->text()=="")? currentPlayer->myScore.sixes = -1: currentPlayer->myScore.sixes = sixScore->text().toInt();
    int num = currentPlayer->playerNum;
    switch(num)
    {
    case 1:
        turnOrder.enqueue(player1);
        break;
    case 2:
        turnOrder.enqueue(player2);
        break;
    case 3:
        turnOrder.enqueue(player3);
        break;
    case 4:
        turnOrder.enqueue(player4);
        break;
    case 5:
        turnOrder.enqueue(player5);
        break;
    }

    on_checkBox1_stateChanged(0);
    on_checkBox2_stateChanged(0);
    on_checkBox3_stateChanged(0);
    on_checkBox4_stateChanged(0);
    on_checkBox5_stateChanged(0);

    playgame();
}

void GameWindow::oneScore_clicked()
{
    int score = 0;
    topScoreSetArray[0] = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value==1)
            score++;
    }
    oneScore->setText(QString::number(score));
    oneScore->setEnabled(false);
    int temp = topSubTotalScore->text().toInt();
    topSubTotalScore->setText(QString::number(temp+score));
    checkTopComplete();
    endTurn();

}

void GameWindow::twoScore_clicked()
{
    int score = 0;
    topScoreSetArray[1] = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value==2)
            score+=2;
    }
    twoScore->setText(QString::number(score));
    twoScore->setEnabled(false);
    int temp = topSubTotalScore->text().toInt();
    topSubTotalScore->setText(QString::number(temp+score));
    checkTopComplete();
    endTurn();
}

void GameWindow::threeScore_clicked()
{
    int score = 0;
    topScoreSetArray[2] = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 3)
            score+=3;
    }
    threeScore->setText(QString::number(score));
    threeScore->setEnabled(false);
    int temp = topSubTotalScore->text().toInt();
    topSubTotalScore->setText(QString::number(temp+score));
    checkTopComplete();
    endTurn();
}

void GameWindow::fourScore_clicked()
{
    int score = 0;
    topScoreSetArray[3] = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 4)
            score+=4;
    }
    fourScore->setText(QString::number(score));
    fourScore->setEnabled(false);
    int temp = topSubTotalScore->text().toInt();
    topSubTotalScore->setText(QString::number(temp+score));
    checkTopComplete();
    endTurn();
}

void GameWindow::fiveScore_clicked()
{
    int score = 0;
    topScoreSetArray[4] = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 5)
            score+=5;
    }
    fiveScore->setText(QString::number(score));
    fiveScore->setEnabled(false);
    int temp = topSubTotalScore->text().toInt();
    topSubTotalScore->setText(QString::number(temp+score));
    checkTopComplete();
    endTurn();

}

void GameWindow::sixScore_clicked()
{
    int score = 0;
    topScoreSetArray[5] = true;
    for(int i = 0; i<5; i++)
    {
        if(diceSet[i]->value == 6)
            score+=6;
    }
    sixScore->setText(QString::number(score));
    sixScore->setEnabled(false);
    int temp = topSubTotalScore->text().toInt();
    topSubTotalScore->setText(QString::number(temp+score));
    checkTopComplete();
    endTurn();
}

void GameWindow::toakScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[0] = true;
    sortDice();
    if(((diceSet[2]->value==diceSet[1]->value)&&(diceSet[1]->value==diceSet[0]->value))
            ||((diceSet[2]->value==diceSet[1]->value)&&(diceSet[1]->value==diceSet[3]->value))
            ||((diceSet[2]->value==diceSet[3]->value)&&(diceSet[3]->value==diceSet[4]->value)))
    {
        for(int i = 0; i<5; i++)
        {
            score += diceSet[i]->value;
        }
    }
    threeOfAKindScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    threeOfAKindScore->setEnabled(false);
    checkBottomComplete();
    endTurn();
}

void GameWindow::foakScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[1] = true;
    sortDice();
    if(((diceSet[3]->value==diceSet[2]->value)&&(diceSet[1]->value==diceSet[0]->value)&&(diceSet[2]->value==diceSet[1]->value))
            ||((diceSet[4]->value==diceSet[2]->value)&&(diceSet[1]->value==diceSet[3]->value)&&(diceSet[2]->value==diceSet[1]->value)))
    {
        for(int i = 0; i<5; i++)
        {
            score += diceSet[i]->value;
        }
    }
    fourOfAKindScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    fourOfAKindScore->setEnabled(false);
    checkBottomComplete();
    endTurn();
}

void GameWindow::fhScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[2] = true;
    sortDice();
    if(((diceSet[2]->value==diceSet[1]->value)&&(diceSet[1]->value==diceSet[0]->value)&&(diceSet[4]->value==diceSet[3]->value))
            ||((diceSet[2]->value==diceSet[3]->value)&&(diceSet[3]->value==diceSet[4]->value)&&(diceSet[0]->value==diceSet[1]->value)))
            score = 25;
    fullHouseScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    fullHouseScore->setEnabled(false);
    checkBottomComplete();
    endTurn();

}

void GameWindow::smsScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[3] = true;
    sortDice();
    if(checkSmallStraight())
     { score = 30;}
    smStraightScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    smStraightScore->setEnabled(false);
    checkBottomComplete();
    endTurn();
}

void GameWindow::lgsScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[4] = true;
    sortDice();
    if((diceSet[0]->value==1&&diceSet[1]->value==2&&diceSet[2]->value==3&&diceSet[3]->value==4&&diceSet[4]->value==5)||
            (diceSet[0]->value==2&&diceSet[1]->value==3&&diceSet[2]->value==4&&diceSet[3]->value==5&&diceSet[4]->value==6))
            score = 40;
    lgStraightScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    lgStraightScore->setEnabled(false);
    checkBottomComplete();
    endTurn();
}

void GameWindow::chanceScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[5] = true;
    for(int i = 0; i<5; i++)
        score+=diceSet[i]->value;
    chanceScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    chanceScore->setEnabled(false);
    checkBottomComplete();
    endTurn();
}

void GameWindow::yahtzeeScore_clicked()
{
    int score = 0;
    bottomScoreSetArray[6] = true;
    sortDice();
    if(diceSet[0]->value==diceSet[4]->value)
            score = 50;
    yahtzeeScore->setText(QString::number(score));
    int temp = bottomSubTotalScore->text().toInt();
    bottomSubTotalScore->setText(QString::number(temp+score));
    yahtzeeScore->setEnabled(false);
    checkBottomComplete();
    endTurn();
}

void GameWindow::die1_clicked(bool s)
{
    diceSet[0]->held = s;
    die1->repaint();
}

void GameWindow::die2_clicked(bool s)
{
    diceSet[1]->held = s;
    die2->repaint();
}
void GameWindow::die3_clicked(bool s)
{
    diceSet[2]->held = s;
    die3->repaint();
}
void GameWindow::die4_clicked(bool s)
{
    diceSet[3]->held = s;
    die4->repaint();
}
void GameWindow::die5_clicked(bool s)
{
    diceSet[4]->held = s;
    die5->repaint();
}

void GameWindow::on_action_Rules_triggered()
{
    Rules->show();
}

void GameWindow::on_checkBox1_stateChanged(int arg1)
{
    if(arg1==2)
        GameWindow::die1_clicked(true);
    else if(arg1==0)
        GameWindow::die1_clicked(false);
}

void GameWindow::on_checkBox2_stateChanged(int arg1)
{
    if(arg1==2)
        GameWindow::die2_clicked(true);
    else if(arg1==0)
        GameWindow::die2_clicked(false);
}

void GameWindow::on_checkBox3_stateChanged(int arg1)
{
    if(arg1==2)
        GameWindow::die3_clicked(true);
    else if(arg1==0)
        GameWindow::die3_clicked(false);
}

void GameWindow::on_checkBox4_stateChanged(int arg1)
{
    if(arg1==2)
        GameWindow::die4_clicked(true);
    else if(arg1==0)
        GameWindow::die4_clicked(false);
}

void GameWindow::on_checkBox5_stateChanged(int arg1)
{
    if(arg1==2)
        GameWindow::die5_clicked(true);
    else if(arg1==0)
        GameWindow::die5_clicked(false);
}
