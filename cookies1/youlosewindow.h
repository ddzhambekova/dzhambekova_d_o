#ifndef YOULOSEWINDOW_H
#define YOULOSEWINDOW_H

#include <QDialog>

namespace Ui {
class youlosewindow;
}

class youlosewindow : public QDialog
{
    Q_OBJECT

public:
    explicit youlosewindow(QWidget *parent = 0);
    ~youlosewindow();

signals:
    void chooseLevelWindow();

private slots:
    void on_backToChooseButton_clicked();

private:
    Ui::youlosewindow *ui;
};

#endif // YOULOSEWINDOW_H
