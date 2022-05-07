#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speed, pixmap, parent)
{

}

void Bullet::advance(int phase)
{
    if(phase == 0)
    {
        moveBy(0, -25);
    }
}

GameObjectType Bullet::getType()
{
    return GameObjectType::BulletType;
}
