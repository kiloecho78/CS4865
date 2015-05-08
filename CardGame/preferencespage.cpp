#include "preferencespage.h"
#include "ui_preferencespage.h"
#include "card.h"

//extern QString *cardBacks;

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


//The following function was supposed to allow the player to change the image
//on the backs of the cards.  Unfortunately I couldn't figure out how to
//access this without crashing the program.
void PreferencesPage::on_changeCards_clicked()
{
    if(ui->bicycleButton->isChecked())
    {
//        *cardBacks = ":/cards/zCardBackBicycle.bmp";
    }
    else if(ui->fishButton->isChecked())
    {
//        *cardBacks = ":/cards/zCardBackFish.bmp";
    }
    else if(ui->hotButton->isChecked())
    {
//        *cardBacks = ":/cards/zCardBackHot.bmp";
    }
    else if(ui->humanityButton->isChecked())
    {
//        cardBacks = ":/cards/zCardBackCAH.bmp";
    }
    else
    {
//        cardBacks = ":/cards/zCardBack.bmp";
    }

}
