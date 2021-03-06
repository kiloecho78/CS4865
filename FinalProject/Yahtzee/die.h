#ifndef DIE_H
#define DIE_H
#include <QWidget>
#include <QPushButton>


class Die: public QPushButton
{
    Q_OBJECT
private:
    int value;
    bool held;
public:
    Die(QWidget *parent);
    void paintEvent(QPaintEvent *ev);
    friend class GameWindow;
};

#endif // DIE_H
