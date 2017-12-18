#include "level1.h"
#include "ui_level1.h"

Level1::Level1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level1)
{  
//    Level1 lev1 = new Level1(this);
//    connect(lev1, &Level1::restart, this, &Level1::show);

    ui->setupUi(this);
    this->setFixedSize(600,400);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setFixedSize(240,240);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,237,237);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addLine(79,0,79,237,QPen(Qt::black));
    scene->addLine(158,0,158,237,QPen(Qt::black));
    scene->addLine(0,79,237,79,QPen(Qt::black));
    scene->addLine(0,158,237,158,QPen(Qt::black));

//    int cookieCount = 1;
//    for (int i=0; i < cookieCount; i++)
//    {
//        Cookie* cookie = new Cookie();
//        scene->addItem(cookie);
//    }

    //timer = new QTimer(this);


//    cells = new QVector<Cell>(9);
//    cells->push_back(CL_CLEAR);
//    cells->push_back(CL_CLEAR);
//    cells->push_back(CL_BLACK);
//    cells->push_back(CL_COOKIE);
//    cells->push_back(CL_CLEAR);
//    cells->push_back(CL_COOKIE);
//    cells->push_back(CL_COOKIE);
//    cells->push_back(CL_CLEAR);
//    cells->push_back(CL_CLEAR);
   //ui->gridField->addItem(cells->at(0), 0,0);



    ui->stepsNumber->display(stepsCount);

    rikki = new Rikki(this);
    scene->addItem(rikki);
    rikki->setPos(172.5,172.5);



//    Cookie *cookie1 = new Cookie(this);
//    scene->addItem(cookie1);
//    cookie1->setPos(177.5,98.5);

//    blackCell *black1 = new blackCell(this);
//    scene->addItem(black1);
//    black1->setPos(0,0);

//    Cookie *cookie2 = new Cookie(this);
//    scene->addItem(cookie2);
//    cookie2->setPos(98.5,98.5);

//    Cookie *cookie3 = new Cookie(this);
//    scene->addItem(cookie3);
//    cookie3->setPos(19.5,177.5);

    //paintEvent(QPaintEvent *e);

//    timer = new QTimer();
//    connect(timer, &QTimer::timeout, rikki, &Rikki::slotGameTimer);
//    timer->start(1000 / 100);


    timerCreateApple = new QTimer();
    //connect(timerCreateApple, &QTimer::timeout, this, &Level1::slotCreateApple);
    timerCreateApple->singleShot(100, this, &Level1::slotCreateApple);


    connect(rikki, &Rikki::signalCheckItem, this, &Level1::slotDeleteApple);

    if (stepsCount < 0)
    {
        QMessageBox::warning(this, "Game Over", "У вас не осталось ходов!");
    }


}



Level1::~Level1()
{
    delete ui;
}


//void Level1::paintEvent(QPaintEvent *e)
//{
//    //Cell cell;
//    QPainter *painter;
//    for(int i=0; i < 9; i++)
//    {
//        switch(cells->at(i))
//        {
//        case CL_CLEAR:
//            break;
//        case CL_COOKIE:
//            painter->setPen(QPen(Qt::black, 2));
//            painter->drawEllipse(0,0, 20, 20);
//            break;
//        case CL_BLACK:
//            painter->setBrush(Qt::black);
//            QPainterPath path;
//            path.addRect(0, 0, 79, 79);
//            painter->drawPath(path);
//            break;
//        }
//    }
//    Q_UNUSED(e);
//}



void Level1::slotDeleteApple(QGraphicsItem *item)
{
    /* Получив сигнал от Мухи
         * Перебираем весь список яблок и удаляем найденное яблоко
         * */
    foreach (QGraphicsItem *cook, cookies)
    {
        if(cook == item)
        {
            scene->removeItem(cook);   // Удаляем со сцены
            cookies.removeOne(item);     // Удаляем из списка
            delete cook;               // Вообще удаляем
            ui->cookiesNumber->display(count+=1);
        }
    }
}

void Level1::slotCreateApple()
{
    Cookie *cookie1 = new Cookie(this);
    scene->addItem(cookie1);
    cookie1->setPos(177.5,98.5);
    cookie1->setZValue(-1);
    cookies.append(cookie1);

    Cookie *cookie2 = new Cookie(this);
    scene->addItem(cookie2);
    cookie2->setPos(98.5,98.5);
    cookie2->setZValue(-1);
    cookies.append(cookie2);

    Cookie *cookie3 = new Cookie(this);
    scene->addItem(cookie3);
    cookie3->setPos(19.5,177.5);
    cookie3->setZValue(-1);
    cookies.append(cookie3);
}

void Level1::on_backToChoose_clicked()
{
    this->close();
    emit chooseLevelWindow();
}

void Level1::on_jumpButton_clicked()
{
    rikki->moveBy(0, -158);
    stepsCount-=1;
    ui->stepsNumber->display(stepsCount);
    if (stepsCount < 0)
    {
        QMessageBox::warning(this, "Game Over", "У вас не осталось ходов!");
    }
}

void Level1::on_upArrow_clicked()
{
    QTimeLine *timerAnim = new QTimeLine(1500);
    timerAnim->setFrameRange(0, 100);
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(rikki);
    anim->setTimeLine(timerAnim);
    timerAnim->start();

    for (int i = 0;i  <= 79; i+=1)
    {
        anim->setPosAt(i / 79.0, QPointF(rikki->x(), rikki->y() - i));
    }
    stepsCount-=1;
    ui->stepsNumber->display(stepsCount);
    if (stepsCount < 0)
    {
        QMessageBox::warning(this, "Game Over", "У вас не осталось ходов!");
    }
}

void Level1::on_downArrow_clicked()
{
    QTimeLine *timerAnim = new QTimeLine(1500);
    timerAnim->setFrameRange(0, 100);
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(rikki);
    anim->setTimeLine(timerAnim);
    timerAnim->start();

    for (int i = 0;i  <= 79; i+=1)
    {
        anim->setPosAt(i / 79.0, QPointF(rikki->x(), rikki->y() + i));
    }

    stepsCount-=1;
    ui->stepsNumber->display(stepsCount);
    if (stepsCount < 0)
    {
        QMessageBox::warning(this, "Game Over", "У вас не осталось ходов!");
    }
}

void Level1::on_leftArrow_clicked()
{
    QTimeLine *timerAnim = new QTimeLine(1500);
    timerAnim->setFrameRange(0, 100);
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(rikki);
    anim->setTimeLine(timerAnim);
    timerAnim->start();

    for (int i = 0;i  <= 79; i+=1)
    {
        anim->setPosAt(i / 79.0, QPointF(rikki->x() - i, rikki->y()));
    }
    angle -= 90;

    //rikki->setRotation(angle);

    stepsCount-=1;
    ui->stepsNumber->display(stepsCount);
    if (stepsCount < 0)
    {
        QMessageBox::warning(this, "Game Over", "У вас не осталось ходов!");
    }
}

void Level1::on_rightArrow_clicked()
{
    QTimeLine *timerAnim = new QTimeLine(1500);
    timerAnim->setFrameRange(0, 100);
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(rikki);
    anim->setTimeLine(timerAnim);
    timerAnim->start();

    for (int i = 0;i  <= 79; i+=1)
    {
        anim->setPosAt(i / 79.0, QPointF(rikki->x() + i, rikki->y()));
    }
    angle += 90;
    //rikki->setRotation(angle);

    stepsCount-=1;
    ui->stepsNumber->display(stepsCount);
    if (stepsCount < 0)
    {
        QMessageBox::warning(this, "Game Over", "У вас не осталось ходов!");
    }
}

void Level1::on_restartButton_clicked()
{
    this->close();
    emit restart();
}
