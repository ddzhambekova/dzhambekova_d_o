#include "rikki.h"

Rikki::Rikki(QObject *parent) : QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
}
void Rikki::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::yellow, 2));
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(0,0,50,50);
    //painter->drawEllipse(boundingRect());
    painter->setBrush(Qt::black);
    painter->drawEllipse(20, 10, 10, 10);


    Q_UNUSED(widget)
    Q_UNUSED(option)
}

QRectF Rikki::boundingRect() const
{
    return QRectF(0,0,79,79);
}


void Rikki::slotGameTimer()
{
//    if(this->x() < 0)
//    {
//              // слева
//    }
//    if(this->x() > 237)
//    {
//        this->setX(240);        // справа
//    }
//    if(this->y() < 0)
//    {
//        this->setY(-240);       // сверху
//    }
//    if(this->y() > 237)
//    {
//        this->setY(240);        // снизу
//    }
    QList<QGraphicsItem *> foundItems = scene()->items((QPolygonF() << mapToScene(0,0) << mapToScene(79,0)
                                                        << mapToScene(79, 79) << mapToScene(0, 79)));
    foreach (QGraphicsItem *item, foundItems)
    {
        if (item == this)
        {
            continue;
        }
        emit signalCheckItem(item);
     }
}
