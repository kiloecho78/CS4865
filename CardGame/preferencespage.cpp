#include "preferencespage.h"
#include "ui_preferencespage.h"

extern QString *cardBacks;
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
        *cardBacks = ":/cards/zCardBackBicycle.bmp";
    }
    else if(ui->fishButton->isChecked())
    {
        *cardBacks = ":/cards/zCardBackFish.bmp";
    }
    else if(ui->hotButton->isChecked())
    {
        *cardBacks = ":/cards/zCardBackHot.bmp";
    }
    else if(ui->humanityButton->isChecked())
    {
        *cardBacks = ":/cards/zCardBackCAH.bmp";
    }
    else
    {
        *cardBacks = ":/cards/zCardBack.bmp";
    }

}
