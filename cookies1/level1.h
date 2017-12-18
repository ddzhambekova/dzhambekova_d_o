#ifndef LEVEL1_H
#define LEVEL1_H

//#include "field.h"
#include "cookie.h"
#include "rikki.h"
#include "blackcell.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QMessageBox>


enum Cell
{
    CL_CLEAR = 0,
    CL_COOKIE = 1,
    //CL_COOKIEWITHTIMER = 2,
    //CL_BOMB = 3,
    CL_BLACK = 4
};

namespace Ui {
class Level1;
}

class Level1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = 0);
    ~Level1();


signals:
    void chooseLevelWindow();
    void restart();

protected:
    //void paintEvent(QPaintEvent *e);

private slots:
    void on_backToChoose_clicked();
    void on_jumpButton_clicked();
    //void slotGameTimer();
    void slotDeleteApple(QGraphicsItem * item);
    void slotCreateApple();


    void on_upArrow_clicked();

    void on_downArrow_clicked();

    void on_leftArrow_clicked();

    void on_rightArrow_clicked();

    void on_restartButton_clicked();

private:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    QTimer *timer;

    int stepsCount = 5;
    qreal angle;
    Rikki *rikki;
    //QVector<Cell> *cells;

    QTimer *timerCreateApple;  // Таймер для периодического создания яблок в игре

    QList<QGraphicsItem *> cookies;  // Список со всеми яблоками, присутствующими в игре
    double count = 0;   // Переменная, которая хранит счёт игре

    //Level1 *lev1;

};

#endif // LEVEL1_H
