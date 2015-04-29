#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>

namespace Ui {
class gameboard;
}

class gameboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameboard(QWidget *parent = 0);
    ~gameboard();

private slots:
    void on_action_Klondike_triggered();

    void on_action_Freecell_triggered();

    void on_action_Redeal_triggered();

    void on_action_Playoff_triggered();

    void on_actionPreference_s_triggered();

    void on_action_Undo_triggered();

    void on_actionRu_les_triggered();

    void on_action_About_triggered();

private:
    Ui::gameboard *ui;
};

#endif // GAMEBOARD_H
