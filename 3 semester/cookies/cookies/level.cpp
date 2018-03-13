#include "level.h"
#include "ui_level.h"

#include<QGraphicsView>
#include<QDebug>

Level::Level(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);
    setFixedSize(545, 465);

    lose = new youlosewindow(this);


    rikki = new Rik();
    rikki->setPic();
    rikki->setZValue(1);
    ui->fieldLayout->addWidget(rikki, 2, 2);

    ui->gridLayout_3->setColumnMinimumWidth(0, 32);
    ui->gridLayout_3->setColumnMinimumWidth(1, 32);
    ui->gridLayout_3->setColumnMinimumWidth(2, 32);
    ui->gridLayout_3->setRowMinimumHeight(0, 32);
    ui->gridLayout_3->setRowMinimumHeight(1, 32);
    ui->gridLayout_3->setRowMinimumHeight(2, 32);

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

    moveList = new QList<Move>;

}

Level::~Level()
{
    delete ui;
}

void Level::on_upArrow_clicked()
{
    moveList->append(M_UP);
    d1 = new drawing();
    d1->pic(P_UP);
    ui->gridLayout_3->addWidget(d1);
    stepsCount -= 1;
    ui->stepsNumber->display(stepsCount);
    if(stepsCount < 0)
    {
        this->close();
        lose->show();
    }
}

void Level::on_downArrow_clicked()
{
    moveList->append(M_DOWN);
    d1 = new drawing();
    d1->pic(P_DOWN);
    ui->gridLayout_3->addWidget(d1);
    stepsCount -= 1;
    ui->stepsNumber->display(stepsCount);
    if(stepsCount < 0)
    {
        this->close();
        lose->show();
    }
}

void Level::on_leftArrow_clicked()
{
    moveList->append(M_LEFT);
    d1 = new drawing();
    d1->pic(P_LEFT);

    ui->gridLayout_3->addWidget(d1);
    stepsCount -= 1;
    ui->stepsNumber->display(stepsCount);
    if(stepsCount < 0)
    {
        this->close();
        lose->show();
    }
}

void Level::on_rightArrow_clicked()
{
    moveList->append(M_RIGHT);
    d1 = new drawing();
    d1->pic(P_RIGHT);

    ui->gridLayout_3->addWidget(d1);
    stepsCount -= 1;
    ui->stepsNumber->display(stepsCount);
    if(stepsCount < 0)
    {
        this->close();
        lose->show();
    }
}

void Level::on_jumpButton_clicked()
{
    moveList->append(M_JUMP);
    d1 = new drawing();
    d1->pic(P_JUMP);
    ui->gridLayout_3->addWidget(d1);
    stepsCount -= 1;
    ui->stepsNumber->display(stepsCount);
    if(stepsCount < 0)
    {
        this->close();
        lose->show();
    }
}

void Level::on_backToChoose_clicked()
{
    this->close();
    emit chooseLevelWindow();
}

void Level::on_startMoveButton_clicked()
{
    for(int i = 0; i < moveList->length(); i+=1)
    {
        rikki->moveRikki(moveList->at(i));
    }
}
