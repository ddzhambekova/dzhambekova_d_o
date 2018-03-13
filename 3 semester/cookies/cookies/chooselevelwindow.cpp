#include "chooselevelwindow.h"
#include "ui_chooselevelwindow.h"

chooseLevelWindow::chooseLevelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseLevelWindow)
{
    ui->setupUi(this);
    setFixedSize(345,385);

    lev = new Level(this);
    connect(lev, &Level::chooseLevelWindow, this, &chooseLevelWindow::show);
    lev2 = new Level2(this);
    connect(lev2, &Level2::chooseLevelWindow, this, &chooseLevelWindow::show);

    lose = new youlosewindow(this);
    connect(lose, &youlosewindow::chooseLevelWindow, this, &chooseLevelWindow::show);
    win = new youWinWindow(this);
    connect(win, &youWinWindow::chooseLW, this, &chooseLevelWindow::show);

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
    lev->show();
}

void chooseLevelWindow::on_l2Button_clicked()
{
    this->close();
    lev2->show();
}

void chooseLevelWindow::on_l3Button_clicked()
{
    this->close();
}

void chooseLevelWindow::on_l4Button_clicked()
{
    this->close();
}
