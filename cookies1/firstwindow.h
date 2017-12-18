#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include"aboutwindow.h"
#include"chooselevelwindow.h"
#include"toolswindow.h"

#include <QDialog>

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = 0);
    ~FirstWindow();

private slots:
    void on_startButton_clicked();

    void on_toolsButton_clicked();

    void on_aboutButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::FirstWindow *ui;
    chooseLevelWindow *chooselw;
    AboutWindow *aboutw;
    ToolsWindow *toolsw;
};

#endif // FIRSTWINDOW_H
