#include "enemyplane.h"

EnemyPlane::EnemyPlane(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void EnemyPlane::advance(int phase)
{
    if(phase == 0)
    {
        if(x() == -70)
        {
            deleteObject();
            return;
        }
        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(object->getType() == GameObjectType::PlaneType ||
                   object->getType() == GameObjectType::BulletType
                  )
                {
                    destroy(0.5);
                    return;
                }
            }
        }
        moveBy(speedX, speedY);
    }
}

GameObjectType EnemyPlane::getType()
{
    return GameObjectType::EnemyPlaneType;
}
