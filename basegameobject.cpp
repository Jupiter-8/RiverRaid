#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, const QPixmap &pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent), m_speedX(speedX), m_speedY(speedY)
{
    setX(x);
    setY(y);
}

void BaseGameObject::setSpeedX(quint8 value)
{
    m_speedX = value;
}

void BaseGameObject::setSpeedY(quint8 value)
{
    m_speedY = value;
}

quint8 BaseGameObject::getSpeedX() const
{
    return m_speedX;
}

quint8 BaseGameObject::getSpeedY() const
{
    return m_speedY;
}

void BaseGameObject::deleteObject()
{
    scene()->removeItem(this);
    delete this;
}
