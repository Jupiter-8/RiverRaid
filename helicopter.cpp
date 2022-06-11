#include "helicopter.h"

Helicopter::Helicopter(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{
    timer->start(1);
}

void Helicopter::advance(int phase)
{
    if(phase == 0)
    {
        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(object->getType() == GameObjectType::LandType)
                {
                    transform.rotate(180, Qt::YAxis);
                    transform.translate(-65,0);
                    this->setTransform(transform);

                    speedX = -speedX;
                }
                else if(object->getType() == GameObjectType::PlaneType ||
                        object->getType() == GameObjectType::BulletType
                       )
                {
                    destroy(0.4);
                    return;
                }
            }
        }
        moveBy(speedX, speedY);
    }
}

GameObjectType Helicopter::getType()
{
    return GameObjectType::Helictopter;
}
