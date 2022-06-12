#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Bullet::advance(int phase)
{
    if(phase == 0)
    {
        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(object->getType() == GameObjectType::ShipType ||
                   object->getType() == GameObjectType::HelictopterType ||
                   object->getType() == GameObjectType::EnemyPlaneType ||
                   object->getType() == GameObjectType::FuelType ||
                   object->getType() == GameObjectType::BridgeType
                  )
                {
                    deleteObject();
                    return;
                }
            }
        }
        if(y() == 0)
            deleteObject();
        else
            moveBy(speedX, speedY);
    }
}

GameObjectType Bullet::getType()
{
    return GameObjectType::BulletType;
}
