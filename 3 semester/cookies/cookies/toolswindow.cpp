#include "toolswindow.h"
#include "ui_toolswindow.h"

ToolsWindow::ToolsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolsWindow)
{
    ui->setupUi(this);
    setFixedSize(345, 385);
}

ToolsWindow::~ToolsWindow()
{
    delete ui;
}

void ToolsWindow::on_backToFWButton_clicked()
{
    this->close();
    emit firstWindow();
}
