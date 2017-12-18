#include "cookie.h"

Cookie::Cookie(QObject *parent) : QObject(parent), QGraphicsItem()
{

}

QRectF Cookie::boundingRect() const
{
    return QRectF(0,0,79,79);
}

void Cookie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->drawEllipse(0, 0, 40, 40);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}
