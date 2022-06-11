#include "plane.h"
#include "bullet.h"

Plane::Plane(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(!object->isDestroyed() &&
                        (object->getType() == GameObjectType::LandType || object->getType() == GameObjectType::ShipType))
                {
                    emit crash();
                    changePixmap(":/images/models/plane_crashed.png");
                }
            }
        }
    }
}

void Plane::destroy()
{

}

GameObjectType Plane::getType()
{
    return GameObjectType::PlaneType;
}
