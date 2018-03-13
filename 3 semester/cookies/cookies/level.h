#ifndef LEVEL_H
#define LEVEL_H

#include "celldraw.h"
#include "rik.h"
#include "youlosewindow.h"
#include "youwinwindow.h"
#include "drawing.h"

#include <QMainWindow>
#include <QPropertyAnimation>
//#include <QStateMachine>
//#include <QState>
//#include <QFinalState>

namespace Ui {
class Level;
}

class Level : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = 0);
    ~Level();


signals:
    void chooseLevelWindow();
    void loseWindow();
    void stm();

private slots:
    void on_upArrow_clicked();

    void on_downArrow_clicked();

    void on_leftArrow_clicked();

    void on_rightArrow_clicked();

    void on_jumpButton_clicked();

    void on_backToChoose_clicked();

    void on_startMoveButton_clicked();

private:
    Ui::Level *ui;
    youlosewindow *lose;

    Rik *rikki;
    int stepsCount = 5;
    int cookieCount = 0;
    int cellwidth = 79;
    QList<Move> *moveList;
    drawing *d1;
    //QList<QPropertyAnimation> *list;
};

#endif // LEVEL_H
