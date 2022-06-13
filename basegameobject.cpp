#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent), speedX(speedX), speedY(speedY), transform(transform), timer(new QTimer(this))
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setX(x);
    setY(y);
    setTransform(transform);
}

void BaseGameObject::setSpeedX(quint8 value)
{
    speedX = value;
}

void BaseGameObject::setSpeedY(quint8 value)
{
    speedY = value;
}

quint8 BaseGameObject::getSpeedX()
{
    return speedX;
}

quint8 BaseGameObject::getSpeedY()
{
    return speedY;
}

void BaseGameObject::changePixmap(QString path)
{
    setPixmap(QPixmap(path));
}

void BaseGameObject::deleteObject()
{
    scene()->removeItem(this);
    delete this;
}
