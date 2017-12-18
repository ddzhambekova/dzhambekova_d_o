#include "blackcell.h"

blackCell::blackCell(QObject *parent) : QObject(parent), QGraphicsItem()
{

}

QRectF blackCell::boundingRect() const
{
    return QRectF(-20,-20,40,40);
}

void blackCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, 79, 79);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

