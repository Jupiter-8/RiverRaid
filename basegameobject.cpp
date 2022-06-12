#include "basegameobject.h"

BaseGameObject::BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent), speedX(speedX), speedY(speedY), transform(transform), destroyed(false), timer(new QTimer(this))
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setX(x);
    setY(y);
    setTransform(transform);
}

void BaseGameObject::destroy(qreal scale)
{
    destroyed = true;
    speedX = 0;
//    timer->start(30);
//    setScale(scale);
//    timer->singleShot(1, this, [this] () { this->changePixmap(":/images/models/destroyed_1.png"); } );
//    timer->singleShot(250, this, [this] () { this->changePixmap(":/images/models/destroyed_2.png"); } );
//    timer->singleShot(500, this, [this] () { this->changePixmap(":/images/models/destroyed_1.png"); } );
//    timer->singleShot(750, this, &BaseGameObject::deleteObject );
    deleteObject();
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

bool BaseGameObject::isDestroyed()
{
    return destroyed;
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
