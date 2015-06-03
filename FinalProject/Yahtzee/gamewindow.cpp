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
    ui->inputBox->hide();
    player1 = new Player("", 1);
    player2 = new Player("", 2);
    player3 = new Player("", 3);
    player4 = new Player("", 4);
    player5 = new Player("", 5);
    turnOrder.enqueue(player1);
    turnOrder.enqueue(player2);
    turnOrder.enqueue(player3);
    turnOrder.enqueue(player4);
    turnOrder.enqueue(player5);
    diceSet[0] = (die1 = new Die(this));
    die1->setMinimumSize(70,70);
    die1->setMaximumSize(70,70);
    ui->diceGridLayout->addWidget(die1,1,0,Qt::AlignCenter);
    diceSet[1] = (die2 = new Die(this));
    die2->setMinimumSize(70,70);
    die2->setMaximumSize(70,70);
    ui->diceGridLayout->addWidget(die2,1,1,Qt::AlignCenter);
    diceSet[2] = (die3 = new Die(this));
    die3->setMinimumSize(70,70);
    die3->setMaximumSize(70,70);
    ui->diceGridLayout->addWidget(die3,1,2,Qt::AlignCenter);
    diceSet[3] = (die4 = new Die(this));
    die4->setMinimumSize(70,70);
    die4->setMaximumSize(70,70);
    ui->diceGridLayout->addWidget(die4,1,3,Qt::AlignCenter);
    diceSet[4] = (die5 = new Die(this));
    die5->setMinimumSize(70,70);
    die5->setMaximumSize(70,70);
    ui->diceGridLayout->addWidget(die5,1,4,Qt::AlignCenter);
    createSet();
    rollButton = new QPushButton();
    rollButton->setText("Roll");
    connect(rollButton,SIGNAL(clicked()),this,SLOT(rollButton_clicked()));
    ui->diceGridLayout->addWidget(rollButton,2,2,Qt::AlignCenter);
    gameColHeader = new QLabel(QString("Yahtzee!"));
    QFont f("Bauhaus 93", 28, QFont::Bold);
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
    for (int n; n<5; n++)
        diceVals[n] = diceSet[n]->value;
    for (int k = 1; k < 5; k++){
        int x = diceSet[k]->value;
        int i;
        for(i = k-1; (i>=0) && (x<diceVals[i]); i--)
            diceVals[i+1] = diceVals[i];
        diceVals[i+1] = x;
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
    if(playerNameColHeader->text()!=currentPlayer->myname)
        playerNameColHeader->setText(currentPlayer->myname);
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
        if(diceVals[i]==x)
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
    if(ui->checkBox1->isChecked() == true)ui->checkBox1->setChecked(false);
    if(ui->checkBox2->isChecked() == true)ui->checkBox2->setChecked(false);
    if(ui->checkBox3->isChecked() == true)ui->checkBox3->setChecked(false);
    if(ui->checkBox4->isChecked() == true)ui->checkBox4->setChecked(false);
    if(ui->checkBox5->isChecked() == true)ui->checkBox5->setChecked(false);
    currentPlayer->rolls = 3;
    playerNameColHeader->setText(currentPlayer->myname);
    setColors(currentPlayer->playerNum);
    (currentPlayer->myScore.ones==-1)? oneScore->setText(""):oneScore->setText(QString::number(currentPlayer->myScore.ones));
    (currentPlayer->myScore.twos==-1)? twoScore->setText(""):twoScore->setText(QString::number(currentPlayer->myScore.twos));
    (currentPlayer->myScore.threes==-1)? threeScore->setText(""):threeScore->setText(QString::number(currentPlayer->myScore.threes));
    (currentPlayer->myScore.fours==-1)? fourScore->setText(""):fourScore->setText(QString::number(currentPlayer->myScore.fours));
    (currentPlayer->myScore.fives==-1)? fiveScore->setText(""):fiveScore->setText(QString::number(currentPlayer->myScore.fives));
    (currentPlayer->myScore.sixes==-1)? sixScore->setText(""):sixScore->setText(QString::number(currentPlayer->myScore.sixes));
    (currentPlayer->myScore.threeOfAKind==-1)? threeOfAKindScore->setText(""):threeOfAKindScore->setText(QString::number(currentPlayer->myScore.threeOfAKind));
    (currentPlayer->myScore.fourOfAKind==-1)? fourOfAKindScore->setText(""):fourOfAKindScore->setText(QString::number(currentPlayer->myScore.fourOfAKind));
    (currentPlayer->myScore.fullHouse==-1)? fullHouseScore->setText(""):fullHouseScore->setText(QString::number(currentPlayer->myScore.fullHouse));
    (currentPlayer->myScore.smStraight==-1)? smStraightScore->setText(""):smStraightScore->setText(QString::number(currentPlayer->myScore.smStraight));
    (currentPlayer->myScore.lgStraight==-1)? lgStraightScore->setText(""):lgStraightScore->setText(QString::number(currentPlayer->myScore.lgStraight));
    (currentPlayer->myScore.chance==-1)? chanceScore->setText(""):chanceScore->setText(QString::number(currentPlayer->myScore.chance));
    (currentPlayer->myScore.yahtzee==-1)? yahtzeeScore->setText(""):yahtzeeScore->setText(QString::number(currentPlayer->myScore.yahtzee));
    (currentPlayer->myScore.topSubTotal==-1)? topSubTotalScore->setText(""):topSubTotalScore->setText(QString::number(currentPlayer->myScore.topSubTotal));
    (currentPlayer->myScore.bonus==-1)? bonusScore->setText(""):bonusScore->setText(QString::number(currentPlayer->myScore.bonus));
    (currentPlayer->myScore.topTotal==-1)? topGrandTotalScore->setText(""):topGrandTotalScore->setText(QString::number(currentPlayer->myScore.topTotal));
    (currentPlayer->myScore.topGrandTotal2==-1)? topGrandTotal2Score->setText(""):topGrandTotal2Score->setText(QString::number(currentPlayer->myScore.topGrandTotal2));
    (currentPlayer->myScore.bottomSubTotal==-1)? bottomSubTotalScore->setText(""):bottomSubTotalScore->setText(QString::number(currentPlayer->myScore.bottomSubTotal));
    (currentPlayer->myScore.grandTotal==-1)? grandTotalScore->setText(""):grandTotalScore->setText(QString::number(currentPlayer->myScore.grandTotal));


    for(int i = 0; i<6; i++)
    {
        topScoreSetArray[i] = currentPlayer->myScore.topScoreSetArray[i];
        bottomScoreSetArray[i] = currentPlayer->myScore.bottomScoreSetArray[i];
    }
    bottomScoreSetArray[7] = currentPlayer->myScore.bottomScoreSetArray[7];
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
    (threeOfAKindScore->text()=="")? currentPlayer->myScore.threeOfAKind = -1: currentPlayer->myScore.threeOfAKind = threeOfAKindScore->text().toInt();
    (fourOfAKindScore->text()=="")? currentPlayer->myScore.fourOfAKind = -1: currentPlayer->myScore.fourOfAKind = fourOfAKindScore->text().toInt();
    (fullHouseScore->text()=="")? currentPlayer->myScore.fullHouse = -1: currentPlayer->myScore.fullHouse = fullHouseScore->text().toInt();
    (smStraightScore->text()=="")? currentPlayer->myScore.smStraight = -1: currentPlayer->myScore.smStraight = smStraightScore->text().toInt();
    (lgStraightScore->text()=="")? currentPlayer->myScore.lgStraight = -1: currentPlayer->myScore.lgStraight = lgStraightScore->text().toInt();
    (chanceScore->text()=="")? currentPlayer->myScore.chance = -1: currentPlayer->myScore.chance = chanceScore->text().toInt();
    (yahtzeeScore->text()=="")? currentPlayer->myScore.yahtzee = -1: currentPlayer->myScore.yahtzee = yahtzeeScore->text().toInt();
    (topSubTotalScore->text()=="")? currentPlayer->myScore.topSubTotal = -1: currentPlayer->myScore.topSubTotal = topSubTotalScore->text().toInt();
    (topGrandTotal2Score->text()=="") ? currentPlayer->myScore.topGrandTotal2 = -1: currentPlayer->myScore.topGrandTotal2 = topGrandTotal2Score->text().toInt();
    (bonusScore->text()=="")? currentPlayer->myScore.bonus = -1: currentPlayer->myScore.bonus = bonusScore->text().toInt();
    (topGrandTotalScore->text()=="")? currentPlayer->myScore.topTotal = -1: currentPlayer->myScore.topTotal = topGrandTotalScore->text().toInt();
    (grandTotalScore->text()=="")? currentPlayer->myScore.grandTotal = -1: currentPlayer->myScore.grandTotal = grandTotalScore->text().toInt();
    (bottomSubTotalScore->text()=="")? currentPlayer->myScore.bottomSubTotal = -1: currentPlayer->myScore.bottomSubTotal = bottomSubTotalScore->text().toInt();

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
    for(int i = 0; i<6; i++)
    {
        currentPlayer->myScore.topScoreSetArray[i] = topScoreSetArray[i];
        currentPlayer->myScore.bottomScoreSetArray[i] = bottomScoreSetArray[i];
    }
    currentPlayer->myScore.bottomScoreSetArray[7] = bottomScoreSetArray[7];
    for(int i = 0; i < 5; i++)
        diceSet[i]->value = 0;
    showDice();
    playgame();
}

void GameWindow::setColors(int playerNumber)
{
    QPalette Pal(palette());
    switch (playerNumber)
    {
    case 1:
        Pal.setColor(QPalette::Background, QColor(85,255,00,255));
        break;
    case 2:
        Pal.setColor(QPalette::Background, QColor(255,0,0,255));
        break;
    case 3:
        Pal.setColor(QPalette::Background, QColor(85,170,255,255));
        break;
    case 4:
        Pal.setColor(QPalette::Background, QColor(255,255,0,255));
        break;
    case 5:
        Pal.setColor(QPalette::Background, QColor(126,253,255,255));
        break;

    default:
        break;
    }

    ui->scoreCardFrame->setPalette(Pal);
    ui->scoreCardFrame->show();
}

void GameWindow::oneScore_clicked()
{
    if(topScoreSetArray[0] == false)
    {
        int score = 0;
        topScoreSetArray[0] = true;
        for(int i = 0; i<5; i++)
        {
            if(diceSet[i]->value==1)
                score++;
        }
        oneScore->setText(QString::number(score));
        int temp = topSubTotalScore->text().toInt();
        topSubTotalScore->setText(QString::number(temp+score));
        checkTopComplete();
        endTurn();
    }
}

void GameWindow::twoScore_clicked()
{
    if(topScoreSetArray[1] == false)
    {
        int score = 0;
        topScoreSetArray[1] = true;
        for(int i = 0; i<5; i++)
        {
            if(diceSet[i]->value==2)
                score+=2;
        }
        twoScore->setText(QString::number(score));
        int temp = topSubTotalScore->text().toInt();
        topSubTotalScore->setText(QString::number(temp+score));
        checkTopComplete();
        endTurn();
    }
}

void GameWindow::threeScore_clicked()
{
    if(topScoreSetArray[2] == false)
    {
        int score = 0;
        topScoreSetArray[2] = true;
        for(int i = 0; i<5; i++)
        {
            if(diceSet[i]->value == 3)
                score+=3;
        }
        threeScore->setText(QString::number(score));
        int temp = topSubTotalScore->text().toInt();
        topSubTotalScore->setText(QString::number(temp+score));
        checkTopComplete();
        endTurn();
    }
}

void GameWindow::fourScore_clicked()
{
    if(topScoreSetArray[3] == false)
    {
        int score = 0;
        topScoreSetArray[3] = true;
        for(int i = 0; i<5; i++)
        {
            if(diceSet[i]->value == 4)
                score+=4;
        }
        fourScore->setText(QString::number(score));
        int temp = topSubTotalScore->text().toInt();
        topSubTotalScore->setText(QString::number(temp+score));
        checkTopComplete();
        endTurn();
    }
}

void GameWindow::fiveScore_clicked()
{
    if(topScoreSetArray[4] == false)
    {
        int score = 0;
        topScoreSetArray[4] = true;
        for(int i = 0; i<5; i++)
        {
            if(diceSet[i]->value == 5)
                score+=5;
        }
        fiveScore->setText(QString::number(score));
        int temp = topSubTotalScore->text().toInt();
        topSubTotalScore->setText(QString::number(temp+score));
        checkTopComplete();
        endTurn();
    }

}

void GameWindow::sixScore_clicked()
{
    if(topScoreSetArray[5] == false)
    {
        int score = 0;
        topScoreSetArray[5] = true;
        for(int i = 0; i<5; i++)
        {
            if(diceSet[i]->value == 6)
                score+=6;
        }
        sixScore->setText(QString::number(score));
        int temp = topSubTotalScore->text().toInt();
        topSubTotalScore->setText(QString::number(temp+score));
        checkTopComplete();
        endTurn();
    }
}

void GameWindow::toakScore_clicked()
{
    if(bottomScoreSetArray[0] == false)
    {
        int score = 0;
        bottomScoreSetArray[0] = true;
        sortDice();
        if(((diceVals[2]==diceVals[1])&&(diceVals[1]==diceVals[0]))
                ||((diceVals[2]==diceVals[1])&&(diceVals[1]==diceVals[3]))
                ||((diceVals[2]==diceVals[3])&&(diceVals[3]==diceVals[4])))
        {
            for(int i = 0; i<5; i++)
            {
                score += diceSet[i]->value;
            }
        }
        threeOfAKindScore->setText(QString::number(score));
        int temp = bottomSubTotalScore->text().toInt();
        bottomSubTotalScore->setText(QString::number(temp+score));
        checkBottomComplete();
        endTurn();
    }
}

void GameWindow::foakScore_clicked()
{
    if(bottomScoreSetArray[1] == false)
    {
        int score = 0;
        bottomScoreSetArray[1] = true;
        sortDice();
        if(((diceVals[3]==diceVals[2])&&(diceVals[1]==diceVals[0])&&(diceVals[2]==diceVals[1]))
                ||((diceVals[4]==diceVals[2])&&(diceVals[1]==diceVals[3])&&(diceVals[2]==diceVals[1])))
        {
            for(int i = 0; i<5; i++)
            {
                score += diceSet[i]->value;
            }
        }
        fourOfAKindScore->setText(QString::number(score));
        int temp = bottomSubTotalScore->text().toInt();
        bottomSubTotalScore->setText(QString::number(temp+score));
        checkBottomComplete();
        endTurn();
    }
}

void GameWindow::fhScore_clicked()
{
    if(bottomScoreSetArray[2] == false)
    {
        int score = 0;
        bottomScoreSetArray[2] = true;
        sortDice();
        if(((diceVals[2]==diceVals[1])&&(diceVals[1]==diceVals[0])&&(diceVals[4]==diceVals[3]))
                ||((diceVals[2]==diceVals[3])&&(diceVals[3]==diceVals[4])&&(diceVals[0]==diceVals[1])))
                score = 25;
        fullHouseScore->setText(QString::number(score));
        int temp = bottomSubTotalScore->text().toInt();
        bottomSubTotalScore->setText(QString::number(temp+score));
        checkBottomComplete();
        endTurn();
    }
}

void GameWindow::smsScore_clicked()
{
    if(bottomScoreSetArray[3] == false)
    {
       int score = 0;
       bottomScoreSetArray[3] = true;
       sortDice();
       if(checkSmallStraight())
       { score = 30;}
       smStraightScore->setText(QString::number(score));
       int temp = bottomSubTotalScore->text().toInt();
       bottomSubTotalScore->setText(QString::number(temp+score));
       checkBottomComplete();
       endTurn();
    }
}

void GameWindow::lgsScore_clicked()
{
    if(bottomScoreSetArray[4] == false)
    {
        int score = 0;
        bottomScoreSetArray[4] = true;
        sortDice();
        if((diceVals[0]==1&&diceVals[1]==2&&diceVals[2]==3&&diceVals[3]==4&&diceVals[4]==5)||
                (diceVals[0]==2&&diceVals[1]==3&&diceVals[2]==4&&diceVals[3]==5&&diceVals[4]==6))
                score = 40;
        lgStraightScore->setText(QString::number(score));
        int temp = bottomSubTotalScore->text().toInt();
        bottomSubTotalScore->setText(QString::number(temp+score));
        checkBottomComplete();
        endTurn();
    }
}

void GameWindow::chanceScore_clicked()
{
    if(bottomScoreSetArray[5] == false)
    {
        int score = 0;
        bottomScoreSetArray[5] = true;
        for(int i = 0; i<5; i++)
            score+=diceSet[i]->value;
        chanceScore->setText(QString::number(score));
        int temp = bottomSubTotalScore->text().toInt();
        bottomSubTotalScore->setText(QString::number(temp+score));
        checkBottomComplete();
        endTurn();
    }
}

void GameWindow::yahtzeeScore_clicked()
{
    if(bottomScoreSetArray[6] == false)
    {
        int score = 0;
        bottomScoreSetArray[6] = true;
        sortDice();
        if(diceVals[0]==diceVals[4])
                score = 50;
        yahtzeeScore->setText(QString::number(score));
        int temp = bottomSubTotalScore->text().toInt();
        bottomSubTotalScore->setText(QString::number(temp+score));
        checkBottomComplete();
        endTurn();
    }
}

void GameWindow::on_action_Rules_triggered()
{
    Rules->show();
}

void GameWindow::on_checkBox1_stateChanged(int arg1)
{
    diceSet[0]->held = arg1;
    die1->repaint();
}

void GameWindow::on_checkBox2_stateChanged(int arg1)
{
    diceSet[1]->held = arg1;
    die2->repaint();
}

void GameWindow::on_checkBox3_stateChanged(int arg1)
{
    diceSet[2]->held = arg1;
    die3->repaint();
}

void GameWindow::on_checkBox4_stateChanged(int arg1)
{
    diceSet[3]->held = arg1;
    die4->repaint();
}

void GameWindow::on_checkBox5_stateChanged(int arg1)
{
    diceSet[4]->held = arg1;
    die5->repaint();
}

void GameWindow::on_player1Button_clicked()
{
    if(ui->player1Button->text()=="Player 1")
    {
        buttonToPaint = 1;
        ui->inputBox->show();
        ui->usernameBox->setFocus();
    }
}

void GameWindow::on_player2Button_clicked()
{
    if(ui->player2Button->text()=="Player 2")
    {
        buttonToPaint = 2;
        ui->inputBox->show();
        ui->usernameBox->setFocus();
    }
}

void GameWindow::on_player3Button_clicked()
{
    if(ui->player3Button->text()=="Player 3")
    {
        buttonToPaint = 3;
        ui->inputBox->show();
        ui->usernameBox->setFocus();
    }
}

void GameWindow::on_player4Button_clicked()
{
    if(ui->player4Button->text()=="Player 4")
    {
        buttonToPaint = 4;
        ui->inputBox->show();
        ui->usernameBox->setFocus();
    }
}

void GameWindow::on_player5Button_clicked()
{
    if(ui->player5Button->text()=="Player 5")
    {
        buttonToPaint = 5;
        ui->inputBox->show();
        ui->usernameBox->setFocus();
    }
}

void GameWindow::on_accept_clicked()
{
    switch(buttonToPaint)
    {
    case 1:
        ui->player1Button->setText(ui->usernameBox->text());
        player1->myname = ui->usernameBox->text();
        break;
    case 2:
        ui->player2Button->setText(ui->usernameBox->text());
        player2->myname = ui->usernameBox->text();
        break;
    case 3:
        ui->player3Button->setText(ui->usernameBox->text());
        player3->myname = ui->usernameBox->text();
        break;
    case 4:
        ui->player4Button->setText(ui->usernameBox->text());
        player4->myname = ui->usernameBox->text();
        break;
    case 5:
        ui->player5Button->setText(ui->usernameBox->text());
        player5->myname = ui->usernameBox->text();
        break;
    default:
        break;
    }
    playerNameColHeader->setText(ui->usernameBox->text());
    buttonToPaint = 0;
    ui->usernameBox->setText("");
    ui->inputBox->hide();
}
