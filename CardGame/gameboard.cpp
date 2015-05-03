#include "gameboard.h"
#include "ui_gameboard.h"
#include "game.h"
#include "klondike.h"



















//globals
Game *game = NULL;

gameboard::gameboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameboard)
{
    ui->setupUi(this);
    t.start();
    Card::Initialize();
}

gameboard::~gameboard()
{
    delete ui;
}

void gameboard::on_actionE_xit_triggered()
{
    exit(1);
}
void gameboard::on_action_Klondike_triggered()
{
    if(game) delete game;
    resize(600,600);
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum));
    game = new Klondike(ui->centralWidget);
    qsrand(t.elapsed());
    game->ReDeal();
//    CardMove::Clear();
    setWindowTitle("Klondike");

}

void gameboard::
on_action_Redeal_triggered()
{

}

void gameboard::on_action_Freecell_triggered()
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

void gameboard::on_action_Match_Game_triggered()
{
     //MatchGame::MatchGame(this);
}
