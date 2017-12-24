#include "level2.h"
#include "ui_level2.h"

Level2::Level2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level2)
{
    ui->setupUi(this);

    lose = new youlosewindow(this);

    setFixedSize(545, 500);

    rikki = new Rik();
    rikki->setPic();
    rikki->setZValue(1);
    ui->fieldLayout_2->addWidget(rikki, 3, 3);


    ui->stepsNumber_2->display(stepsCount);
    ui->cookiesNumber_2->display(cookieCount);

    celldraw *lbl1 = new celldraw();
    lbl1->setPic(CL_COOKIE);

    celldraw *lbl2 = new celldraw();
    lbl2->setPic(CL_BOMB);

    celldraw *lbl3 = new celldraw();
    lbl3->setPic(CL_BLACK);

    celldraw *lbl4 = new celldraw();
    lbl4->setPic(CL_CLEAR);

    celldraw *lbl5 = new celldraw();
    lbl5->setPic(CL_CLEAR);

    celldraw *lbl6 = new celldraw();
    lbl6->setPic(CL_CLEAR);

    celldraw *lbl7 = new celldraw();
    lbl7->setPic(CL_COOKIE);

    celldraw *lbl8 = new celldraw();
    lbl8->setPic(CL_BLACK);

    celldraw *lbl9 = new celldraw();
    lbl9->setPic(CL_BOMB);

    celldraw *lbl10 = new celldraw();
    lbl10->setPic(CL_BLACK);

    celldraw *lbl11 = new celldraw();
    lbl11->setPic(CL_CLEAR);

    celldraw *lbl12 = new celldraw();
    lbl12->setPic(CL_CLEAR);

    celldraw *lbl13 = new celldraw();
    lbl13->setPic(CL_CLEAR);

    celldraw *lbl14 = new celldraw();
    lbl14->setPic(CL_COOKIE);

    celldraw *lbl15 = new celldraw();
    lbl15->setPic(CL_CLEAR);


    ui->fieldLayout_2->addWidget(lbl1, 0, 0);
    ui->fieldLayout_2->addWidget(lbl2, 0, 1);
    ui->fieldLayout_2->addWidget(lbl3, 0, 2);
    ui->fieldLayout_2->addWidget(lbl4, 0, 3);

    ui->fieldLayout_2->addWidget(lbl5, 1, 0);
    ui->fieldLayout_2->addWidget(lbl6, 1, 1);
    ui->fieldLayout_2->addWidget(lbl7, 1, 2);
    ui->fieldLayout_2->addWidget(lbl8, 1, 3);

    ui->fieldLayout_2->addWidget(lbl9, 2, 0);
    ui->fieldLayout_2->addWidget(lbl10, 2, 1);
    ui->fieldLayout_2->addWidget(lbl11, 2, 2);
    ui->fieldLayout_2->addWidget(lbl12, 2, 3);

    ui->fieldLayout_2->addWidget(lbl13, 3, 0);
    ui->fieldLayout_2->addWidget(lbl14, 3, 1);
    ui->fieldLayout_2->addWidget(lbl15, 3, 2);

    moveList = new QList<Move>;

}

Level2::~Level2()
{
    delete ui;
}

void Level2::on_upArrow_2_clicked()
{
    moveList->append(M_UP);
}

void Level2::on_downArrow_2_clicked()
{
    moveList->append(M_DOWN);
}

void Level2::on_leftArrow_2_clicked()
{
    moveList->append(M_LEFT);
}

void Level2::on_rightArrow_2_clicked()
{
    moveList->append(M_RIGHT);
}

void Level2::on_jumpButton_2_clicked()
{
    moveList->append(M_JUMP);
}

void Level2::on_backToChoose_clicked()
{
    this->close();
    emit chooseLevelWindow();
}

void Level2::on_startMoveButton_clicked()
{
    for(int i = 0; i < moveList->length(); i+=1)
    {
        rikki->moveRikki(moveList->at(i));
        stepsCount -= 1;
        ui->stepsNumber_2->display(stepsCount);
        if(stepsCount < 0)
        {
            this->close();
            lose->show();
        }
    }
}
