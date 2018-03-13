#ifndef CELLDRAW_H
#define CELLDRAW_H

#include <QLabel>
#include <QGraphicsItem>
#include <QCoreApplication>

enum Cell
{
    CL_CLEAR = 0,
    CL_COOKIE = 1,
    //CL_COOKIEWITHTIMER = 2,
    CL_BOMB = 3,
    CL_BLACK = 4
};

class celldraw : public QLabel, public QGraphicsItem
{
public:
    celldraw();
    void setPic(Cell cell);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:



};

#endif // CELLDRAW_H
