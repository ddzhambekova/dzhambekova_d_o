#include "level.h"
#include "ui_level.h"

#include<QGraphicsView>

Level::Level(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);
    setFixedSize(545, 465);

    lose = new youlosewindow(this);



//    QList<QString> list;
//    QLabel *lbl1 = new QLabel(this);
//    QString *r = new QString("rr");
//    list << r;
    //list[0] = new QLabel();

    rikki = new Rik();
    rikki->setPic();
    rikki->setZValue(1);
    ui->fieldLayout->addWidget(rikki, 2, 2);


    ui->stepsNumber->display(stepsCount);
    ui->cookiesNumber->display(cookieCount);

    celldraw *lbl1 = new celldraw();
    lbl1->setPic(CL_COOKIE);

    celldraw *lbl2 = new celldraw();
    lbl2->setPic(CL_BOMB);

    celldraw *lbl3 = new celldraw();
    lbl3->setPic(CL_BLACK);

    celldraw *lbl4 = new celldraw();
    lbl4->setPic(CL_CLEAR);

    celldraw *lbl5 = new celldraw();
    lbl5->setPic(CL_COOKIE);

    celldraw *lbl6 = new celldraw();
    lbl6->setPic(CL_CLEAR);

    celldraw *lbl7 = new celldraw();
    lbl7->setPic(CL_COOKIE);

    celldraw *lbl8 = new celldraw();
    lbl8->setPic(CL_BLACK);

    ui->fieldLayout->addWidget(lbl1, 0, 0);
    ui->fieldLayout->addWidget(lbl2, 0, 1);
    ui->fieldLayout->addWidget(lbl3, 0, 2);

    ui->fieldLayout->addWidget(lbl4, 1, 0);
    ui->fieldLayout->addWidget(lbl5, 1, 1);
    ui->fieldLayout->addWidget(lbl6, 1, 2);

    ui->fieldLayout->addWidget(lbl7, 2, 0);
    ui->fieldLayout->addWidget(lbl8, 2, 1);

//    QStateMachine machine;
//    QState *st1 = new QState();
//    st1->assignProperty(rikki, "coord", QRectF(168, 278, 79, 79));
//    QState *st2 = new QState();
//    st2->assignProperty(rikki, "coord", QRectF(89, 199, 79, 79));
//    QFinalState *st3 = new QFinalState();
//    st1->addTransition(rikki, SIGNAL(stm()), st2);
//    st2->addTransition(rikki, );
//    machine.addState(st1);
//    machine.addState(st2);
//    machine.setInitialState(st1);
//    machine.start();



}

Level::~Level()
{
    delete ui;
}

void Level::on_upArrow_clicked()
{
    if(stepsCount <= 0)
    {
        this->close();
        lose->show();
    }

    ui->stepsNumber->display(stepsCount-=1);

    QPropertyAnimation *animation = new QPropertyAnimation(rikki, "geometry");
    animation->setDuration(1000);
    int x1(rikki->QWidget::x()), y1(rikki->QWidget::y()), x2(rikki->QWidget::x() + cellwidth), y2(rikki->QWidget::y() + cellwidth);
    animation->setStartValue(QRectF(QPointF(x1, y1), QPointF(x2, y2)));
    animation->setEndValue(QRectF(QPointF(x1, y1 - cellwidth), QPointF(x2, y2 - cellwidth)));

    animation->start();

}

void Level::on_downArrow_clicked()
{
    if(stepsCount <= 0)
    {
        this->close();
        lose->show();
    }
    ui->stepsNumber->display(stepsCount-=1);

    QPropertyAnimation *animation = new QPropertyAnimation(rikki, "geometry");
    animation->setDuration(1000);
    int x1(rikki->QWidget::x()), y1(rikki->QWidget::y()), x2(rikki->QWidget::x() + cellwidth), y2(rikki->QWidget::y() + cellwidth);
    rikki->setZValue(1);
    animation->setStartValue(QRectF(QPointF(x1, y1), QPointF(x2, y2)));
    animation->setEndValue(QRectF(QPointF(x1, y1 + cellwidth), QPointF(x2, y2 + cellwidth)));

    animation->start();
}

void Level::on_leftArrow_clicked()
{
    if(stepsCount <= 0)
    {
        this->close();
        lose->show();
    }
    ui->stepsNumber->display(stepsCount-=1);

    QPropertyAnimation *animation = new QPropertyAnimation(rikki, "geometry");
    animation->setDuration(1000);
    int x1(rikki->QWidget::x()), y1(rikki->QWidget::y()), x2(rikki->QWidget::x() + cellwidth), y2(rikki->QWidget::y() + cellwidth);
    rikki->setZValue(1);
    animation->setStartValue(QRectF(QPointF(x1, y1), QPointF(x2, y2)));
    animation->setEndValue(QRectF(QPointF(x1 - cellwidth, y1), QPointF(x2 - cellwidth, y2)));

    animation->start();
}

void Level::on_rightArrow_clicked()
{
    if(stepsCount <= 0)
    {
        this->close();
        lose->show();
    }
    ui->stepsNumber->display(stepsCount-=1);

    QPropertyAnimation *animation = new QPropertyAnimation(rikki, "geometry");
    animation->setDuration(1000);
    int x1(rikki->QWidget::x()), y1(rikki->QWidget::y()), x2(rikki->QWidget::x() + cellwidth), y2(rikki->QWidget::y() + cellwidth);
    rikki->setZValue(1);
    animation->setStartValue(QRectF(QPointF(x1, y1), QPointF(x2, y2)));
    animation->setEndValue(QRectF(QPointF(x1 + cellwidth, y1), QPointF(x2 + cellwidth, y2)));

    animation->start();
}

void Level::on_jumpButton_clicked()
{
    if(stepsCount <= 0)
    {
        this->close();
        lose->show();
    }
    ui->stepsNumber->display(stepsCount-=1);

    QPropertyAnimation *animation = new QPropertyAnimation(rikki, "geometry");
    animation->setDuration(1500);
    int x1(rikki->QWidget::x()), y1(rikki->QWidget::y()), x2(rikki->QWidget::x() + cellwidth), y2(rikki->QWidget::y() + cellwidth);
    rikki->setZValue(1);
    animation->setStartValue(QRectF(QPointF(x1, y1), QPointF(x2, y2)));
    animation->setEndValue(QRectF(QPointF(x1, y1 - 2 * cellwidth), QPointF(x2, y2 - 2 * cellwidth)));

    animation->start();
}

void Level::on_backToChoose_clicked()
{
    this->close();
    emit chooseLevelWindow();
}
