#include "yahtzee.h"
#include "ui_yahtzee.h"

Yahtzee::Yahtzee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Yahtzee)
{
    ui->setupUi(this);
}

Yahtzee::~Yahtzee()
{
    delete ui;
}
