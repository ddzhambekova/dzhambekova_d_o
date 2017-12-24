#ifndef LEVEL2_H
#define LEVEL2_H

#include"celldraw.h"
#include"rik.h"
#include"youlosewindow.h"
#include"youwinwindow.h"

#include <QMainWindow>
#include <QPropertyAnimation>

namespace Ui {
class Level2;
}

class Level2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level2(QWidget *parent = 0);
    ~Level2();

signals:
    void chooseLevelWindow();
    void loseWindow();
    void stm();

private slots:
    void on_upArrow_2_clicked();

    void on_downArrow_2_clicked();

    void on_leftArrow_2_clicked();

    void on_rightArrow_2_clicked();

    void on_jumpButton_2_clicked();

    void on_backToChoose_clicked();

    void on_startMoveButton_clicked();

private:
    Ui::Level2 *ui;
    youlosewindow *lose;

    Rik *rikki;
    int stepsCount = 7;
    int cookieCount = 0;
    int cellwidth = 79;
    QList<Move> *moveList;

};

#endif // LEVEL2_H
