#include "rik.h"

Rik::Rik()
{

}

void Rik::setPic()
{
    this->setPixmap(QPixmap("Z:/qt/qtprojects/images/zverek.png"));

}

QRectF Rik::boundingRect() const
{
    return QRectF(this->rect());
}

void Rik::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setPic();
    Q_UNUSED(option)
    Q_UNUSED(widget)
    Q_UNUSED(painter)
}


