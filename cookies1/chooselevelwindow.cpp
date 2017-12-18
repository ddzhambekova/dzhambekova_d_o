#include "chooselevelwindow.h"
#include "ui_chooselevelwindow.h"

chooseLevelWindow::chooseLevelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseLevelWindow)
{
    ui->setupUi(this);
    setFixedSize(345,385);
    lev1 = new Level1(this);
    connect(lev1, &Level1::chooseLevelWindow, this, &chooseLevelWindow::show);
    lose = new youlosewindow(this);
    connect(lose, &youlosewindow::chooseLevelWindow, this, &chooseLevelWindow::show);

}

chooseLevelWindow::~chooseLevelWindow()
{
    delete ui;
}

void chooseLevelWindow::on_backToFWButton_clicked()
{
    this->close();
    emit firstWindow();
}

void chooseLevelWindow::on_l1Button_clicked()
{
    this->close();
    lev1->show();
}
