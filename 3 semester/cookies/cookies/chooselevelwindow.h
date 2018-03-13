#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include "level.h"
#include "level2.h"

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

    void on_l2Button_clicked();

    void on_l3Button_clicked();

    void on_l4Button_clicked();

private:
    Ui::chooseLevelWindow *ui;
    youlosewindow *lose;
    youWinWindow *win;
    Level *lev;
    Level2 *lev2;
};

#endif // CHOOSELEVELWINDOW_H
