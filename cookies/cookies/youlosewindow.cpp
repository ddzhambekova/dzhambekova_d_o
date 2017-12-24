#include "youlosewindow.h"
#include "ui_youlosewindow.h"

youlosewindow::youlosewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::youlosewindow)
{
    ui->setupUi(this);

}

youlosewindow::~youlosewindow()
{
    delete ui;
}

void youlosewindow::on_backToChooseButton_clicked()
{
    this->close();
    emit youlosewindow::chooseLevelWindow();
}
