#include "firstwindow.h"
#include "ui_firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    setFixedSize(345,385);


    chooselw = new chooseLevelWindow();
    connect(chooselw, &chooseLevelWindow::firstWindow, this, &FirstWindow::show);

    aboutw = new AboutWindow();
    connect(aboutw, &AboutWindow::firstWindow, this, &FirstWindow::show);

    toolsw = new ToolsWindow();
    connect(toolsw, &ToolsWindow::firstWindow, this, &FirstWindow::show);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::on_startButton_clicked()
{
    chooselw->show();
    this->close();
}

void FirstWindow::on_toolsButton_clicked()
{
    toolsw->show();
    this->close();
}

void FirstWindow::on_aboutButton_clicked()
{
    aboutw->show();
    this->close();
}

void FirstWindow::on_exitButton_clicked()
{
    close();
}
