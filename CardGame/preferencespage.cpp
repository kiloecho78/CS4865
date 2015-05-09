#include "preferencespage.h"
#include "ui_preferencespage.h"
#include "card.h"

PreferencesPage::PreferencesPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesPage)
{
    ui->setupUi(this);
}

PreferencesPage::~PreferencesPage()
{
    delete ui;
}

void PreferencesPage::on_changeCards_clicked()
{
    if(ui->bicycleButton->isChecked())
    {
        Card::SetBacks(4);
    }
    else if(ui->fishButton->isChecked())
    {
        Card::SetBacks(2);
    }
    else if(ui->hotButton->isChecked())
    {
        Card::SetBacks(3);
    }
    else if(ui->humanityButton->isChecked())
    {
        Card::SetBacks(1);
    }
    else
    {
        Card::SetBacks(0);
    }
}
