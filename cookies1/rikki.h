#ifndef RIKKI_H
#define RIKKI_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Rikki : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Rikki(QObject *parent = 0);
    ~Rikki() = default;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void signalCheckItem(QGraphicsItem *item);

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;


private:
    qreal angle;
    //int steps;


};

#endif // RIKKI_H
