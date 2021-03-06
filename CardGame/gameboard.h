#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QtGui>
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include "pile.h"
#include "card.h"

namespace Ui {
class gameboard;
}

class gameboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameboard(QWidget *parent = 0);
    ~gameboard();

public slots:
    void on_action_Klondike_triggered();

    void on_action_Freecell_triggered();

    void on_action_Redeal_triggered();

    void on_actionPreference_s_triggered();

    void on_action_Undo_triggered();

    void on_actionE_xit_triggered();

    void on_action_Match_Game_triggered();

private:
    Ui::gameboard *ui;
    QTime t;
    void DealKlondike();

    void DealFreeCell();
    void CleanUp();
    Card *deck[104];

public:
    bool Deal3(){return true;}
    void PlayOff(Card * c);

    void CardClicked(Card * c);
    void KlondikeDeal();

private slots:
    void on_action_About_triggered();

    void on_action_Playoff_triggered();

    void on_actionRu_les_triggered();

};
#endif // GAMEBOARD_H
