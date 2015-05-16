#ifndef DIE_H
#define DIE_H
#include <QWidget>
#include <QLabel>


class Die: public QLabel
{
    Q_OBJECT
private:
    int value;
    bool held;
    int pos;
public:
    Die(QWidget *parent=0);
    ~Die();
    void paintEvent(QPaintEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void setPos(int p);
    void createSet();
};

#endif // DIE_H
