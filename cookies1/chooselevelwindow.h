#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include "level1.h"
#include "youlosewindow.h"

#include <QDialog>

namespace Ui {
class chooseLevelWindow;
}

class chooseLevelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit chooseLevelWindow(QWidget *parent = 0);
    ~chooseLevelWindow();

signals:
    void firstWindow();

private slots:
    void on_backToFWButton_clicked();

    void on_l1Button_clicked();

private:
    Ui::chooseLevelWindow *ui;
    Level1 *lev1;
    youlosewindow *lose;
};

#endif // CHOOSELEVELWINDOW_H
