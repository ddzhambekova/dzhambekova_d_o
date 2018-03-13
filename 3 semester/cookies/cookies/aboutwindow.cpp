#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    setFixedSize(345, 385);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_backToFWButton_clicked()
{
    this->close();
    emit firstWindow();
}
