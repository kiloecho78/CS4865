#include "gameboard.h"
#include "ui_gameboard.h"
#include "game.h"
#include "klondike.h"
#include "freecell.h"
#include "help.h"
#include "aboutdialog.h"
#include <QtGui>
#include <QWidget>
#include <QLabel>
//#include <QtUiTools/QtUiToolsDepends>
#include "card.h"
#include "pile.h"
#include "cardmove.h"
#include "winningdialog.h"
#include "aboutdialog.h"
#include "help.h"
#include "matchgame.h"

extern AboutDialog *About;
extern Help *help;
extern WinningDialog *win;
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
    Cardmove::Clear();
    setWindowTitle("Klondike");

}

void gameboard::
on_action_Redeal_triggered()
{
    game->ReDeal();
}

void gameboard::on_action_Freecell_triggered()
{
    if(game) delete game;
    resize(700,600);
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum));
    game = new Freecell(ui->centralWidget);
    qsrand(t.elapsed());
    game->ReDeal();
    Cardmove::Clear();
    setWindowTitle("Freecell");
}



void gameboard::on_action_Playoff_triggered()
{
    game->PlayOffAll();
}

void gameboard::on_actionPreference_s_triggered()
{

}

void gameboard::on_action_Undo_triggered()
{
    Cardmove::UndoMove();
}

void gameboard::on_actionRu_les_triggered()
{
    help->show();
}

void gameboard::on_action_About_triggered()
{
    About->show();
}

void gameboard::on_action_Match_Game_triggered()
{
    if(game) delete game;
    resize(660,795);
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum));
    game = new MatchGame(ui->centralWidget);
    qsrand(t.elapsed());
    game->ReDeal();
    Cardmove::Clear();
    setWindowTitle("Match Game");
}
