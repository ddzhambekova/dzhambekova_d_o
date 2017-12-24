#ifndef RIK_H
#define RIK_H

#include <QLabel>
#include <QGraphicsItem>
#include<QList>

enum Move
{
    M_UP = 0,
    M_DOWN,
    M_LEFT,
    M_RIGHT,
    M_JUMP
};

class Rik : public QLabel, public QGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
public:
    Rik();
    void setPic();
    void moveRikki(Move move);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //QList<Move> *list;


};

#endif // RIK_H
