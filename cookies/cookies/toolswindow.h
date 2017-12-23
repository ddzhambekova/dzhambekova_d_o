#ifndef TOOLSWINDOW_H
#define TOOLSWINDOW_H

#include <QDialog>

namespace Ui {
class ToolsWindow;
}

class ToolsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ToolsWindow(QWidget *parent = 0);
    ~ToolsWindow();

signals:
    void firstWindow();

private slots:
    void on_backToFWButton_clicked();

private:
    Ui::ToolsWindow *ui;
};

#endif // TOOLSWINDOW_H
