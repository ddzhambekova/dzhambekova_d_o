#include "youwinwindow.h"
#include "ui_youwinwindow.h"

youWinWindow::youWinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::youWinWindow)
{
    ui->setupUi(this);
    ui->star1->hide();
    ui->star2->hide();
    ui->star3->hide();
}

youWinWindow::~youWinWindow()
{
    delete ui;
}

void youWinWindow::draw(int cookieCount)
{
    if (1 == cookieCount)
    {
        ui->star2->show();
    }
    if (2 == cookieCount)
    {
        ui->star1->show();
        ui->star3->show();
    }
    if (3 == cookieCount)
    {
        ui->star1->show();
        ui->star2->show();
        ui->star3->show();
    }
}

void youWinWindow::on_toChooseButton_clicked()
{
    this->close();
    emit chooseLW();
}
