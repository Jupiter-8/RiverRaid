#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, QPixmap pixmap, QGraphicsItem *parent)
    :QGraphicsPixmapItem(pixmap, parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setX(x);
    setY(y);
}

void BaseGameObject::setSpeed(quint32 value)
{
    speed = value;
}
