#include "getplayernamedialog.h"
#include "ui_getplayernamedialog.h"

GetPlayerNameDialog::GetPlayerNameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetPlayerNameDialog)
{
    ui->setupUi(this);
}

GetPlayerNameDialog::~GetPlayerNameDialog()
{
    delete ui;
}
