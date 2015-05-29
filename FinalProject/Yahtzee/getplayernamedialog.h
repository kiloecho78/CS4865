#ifndef GETPLAYERNAMEDIALOG_H
#define GETPLAYERNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class GetPlayerNameDialog;
}

class GetPlayerNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GetPlayerNameDialog(QWidget *parent = 0);
    ~GetPlayerNameDialog();

private:
    Ui::GetPlayerNameDialog *ui;
};

#endif // GETPLAYERNAMEDIALOG_H
