#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent), speed(speed)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setX(x);
    setY(y);
}

void BaseGameObject::setSpeed(quint8 value)
{
    speed = value;
}
