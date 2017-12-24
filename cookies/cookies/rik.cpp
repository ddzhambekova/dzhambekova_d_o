#include "rik.h"

Rik::Rik()
{

}

void Rik::setPic()
{
    this->setPixmap(QPixmap(":/images/images/zverek.png"));

}

void Rik::moveRikki(Move move)
{
    switch(move)
    {
    case(M_UP):
        this->move(this->QWidget::x(), this->QWidget::y() - 79);
        break;
    case(M_DOWN):
        this->move(this->QWidget::x(), this->QWidget::y() + 79);
        break;
    case(M_LEFT):
        this->move(this->QWidget::x() - 79, this->QWidget::y());
        break;
    case(M_RIGHT):
        this->move(this->QWidget::x() + 79, this->QWidget::y());
        break;
    case(M_JUMP):
        this->move(this->QWidget::x(), this->QWidget::y() - 158);
        break;
    }
}

QRectF Rik::boundingRect() const
{
    return QRectF(this->rect());
}

void Rik::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setPic();
    setZValue(1);
    Q_UNUSED(option)
    Q_UNUSED(widget)
    Q_UNUSED(painter)
}


