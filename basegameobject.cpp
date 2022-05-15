#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent), speedX(speedX), speedY(speedY), transform(transform)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setX(x);
    setY(y);
    setTransform(transform);
}

void BaseGameObject::setSpeedX(quint8 speed)
{
    speedX = speed;
}
