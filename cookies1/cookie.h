#ifndef COOKIE_H
#define COOKIE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Cookie : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Cookie(QObject *parent = 0);
    ~Cookie() = default;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

protected:
    QRectF boundingRect() const;
    //void advance(int phase);


private:
};

#endif // COOKIE_H
