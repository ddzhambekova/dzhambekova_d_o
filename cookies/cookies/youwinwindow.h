#ifndef YOUWINWINDOW_H
#define YOUWINWINDOW_H

#include <QDialog>

namespace Ui {
class youWinWindow;
}

class youWinWindow : public QDialog
{
    Q_OBJECT

public:
    explicit youWinWindow(QWidget *parent = 0);
    ~youWinWindow();
    void draw(int cookieCount);

signals:
    void chooseLW();

private slots:
    void on_toChooseButton_clicked();

private:
    Ui::youWinWindow *ui;
};

#endif // YOUWINWINDOW_H
