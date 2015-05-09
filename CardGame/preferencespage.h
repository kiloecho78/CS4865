#ifndef PREFERENCESPAGE_H
#define PREFERENCESPAGE_H

#include <QDialog>

namespace Ui {
class PreferencesPage;
}

class PreferencesPage : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesPage(QWidget *parent = 0);
    ~PreferencesPage();

private slots:
    void on_changeCards_clicked();

private:
    Ui::PreferencesPage *ui;
};

#endif // PREFERENCESPAGE_H
