#include "fuel.h"

Fuel::Fuel(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Fuel::advance(int phase)
{
    if(phase == 0)
    {
        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(object->getType() == GameObjectType::BulletType)
                {
                    if(!isDestroyed())
                        emit addPoints(80);
                    destroy(0.5);

                    return;
                }
            }
        }
        moveBy(speedX, speedY);
    }
}

GameObjectType Fuel::getType()
{
    return GameObjectType::FuelType;
}
