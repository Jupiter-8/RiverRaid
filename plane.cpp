#include "plane.h"
#include "bullet.h"

Plane::Plane(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent), fuelAmount(10000), isRefuelling(false)
{

}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!isRefuelling && fuelAmount - speedY > 0)
            fuelAmount -= speedY;
        else if(fuelAmount - speedY <= 0)
            emit noFuel();

        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(!object->isDestroyed())
                {
                    if(object->getType() == GameObjectType::LandType ||
                       object->getType() == GameObjectType::ShipType ||
                       object->getType() == GameObjectType::EnemyPlaneType
                    )
                    {
                        emit crash();
                        changePixmap(":/images/models/plane_crashed.png");
                    }
                    else if(object->getType() == GameObjectType::FuelType)
                    {
                        isRefuelling = true;
                        fuelAmount += 15;
                    }
                    isRefuelling = false;
                }
            }
        }
    }
}

GameObjectType Plane::getType()
{
    return GameObjectType::PlaneType;
}
