#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, QGraphicsItem *parent, QPixmap pixmap)
    : BaseGameObject(x, y, pixmap, parent)
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
    return GameObjectType::bullet;
}
