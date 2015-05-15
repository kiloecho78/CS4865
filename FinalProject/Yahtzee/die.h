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
public:
    Die(QWidget *parent =0);
    ~Die();
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // DIE_H
