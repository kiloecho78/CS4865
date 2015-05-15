#ifndef DIE_H
#define DIE_H
#include <QWidget>
#include <QLabel>



class die: public QLabel
{
    Q_OBJECT
private:
    int value;
    bool held;
public:
    die(QWidget *parent =0);
    ~die();
};

#endif // DIE_H
