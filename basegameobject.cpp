#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent), speedX(speedX), speedY(speedY), timer(new QTimer(this))
{
    mediaPlayer = new QMediaPlayer(this->scene());
    mediaPlayer->setVolume(5);
    setX(x);
    setY(y);
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
