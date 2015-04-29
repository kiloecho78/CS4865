#include "gameboard.h"
#include "ui_gameboard.h"
#include "matchgame.h"
gameboard::gameboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameboard)
{
    Card::Initialize();
    ui->setupUi(this);
}

gameboard::~gameboard()
{
    delete ui;
}

void gameboard::on_action_Klondike_triggered()
{

}

void gameboard::on_action_Freecell_triggered()
{

}

void gameboard::on_action_Redeal_triggered()
{

}

void gameboard::on_action_Playoff_triggered()
{

}

void gameboard::on_actionPreference_s_triggered()
{

}

void gameboard::on_action_Undo_triggered()
{

}

void gameboard::on_actionRu_les_triggered()
{

}

void gameboard::on_action_About_triggered()
{

}

void gameboard::on_actionE_xit_triggered()
{
    close();
}

void gameboard::on_action_Match_Game_triggered()
{
     MatchGame::MatchGame(this);
}
