#include "celldraw.h"

celldraw::celldraw()
{

}

void celldraw::setPic(Cell cell)
{
    switch(cell)
    {
    case CL_COOKIE:
        this->setPixmap(QPixmap(":/img/cookie79.png"));
        setZValue(-1);
        break;
    case CL_BLACK:
        this->setPixmap(QPixmap(":/img/black.png"));
        setZValue(-1);
        break;
    case CL_BOMB:
        this->setPixmap(QPixmap(":/img/bomb_PNG26.png"));
        setZValue(-1);
    case CL_CLEAR:
        break;
    }
}

QRectF celldraw::boundingRect() const
{
    return QRectF(this->rect());
}

void celldraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    Q_UNUSED(painter)
}