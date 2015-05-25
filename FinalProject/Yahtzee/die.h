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
    ~Die();
    void paintEvent(QPaintEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    friend class GameWindow;
    
};

#endif // DIE_H
