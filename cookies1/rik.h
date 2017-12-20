#ifndef RIK_H
#define RIK_H

#include <QLabel>
#include <QGraphicsItem>

class Rik : public QLabel, public QGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
public:
    Rik();
    void setPic();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // RIK_H
