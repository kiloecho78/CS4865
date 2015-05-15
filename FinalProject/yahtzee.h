#ifndef YAHTZEE_H
#define YAHTZEE_H

#include <QMainWindow>

namespace Ui {
class Yahtzee;
}

class Yahtzee : public QMainWindow
{
    Q_OBJECT

public:
    explicit Yahtzee(QWidget *parent = 0);
    ~Yahtzee();

private:
    Ui::Yahtzee *ui;
};

#endif // YAHTZEE_H
