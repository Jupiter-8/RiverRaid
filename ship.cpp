#include "ship.h"

#include <QTimer>
#include <QTransform>

Ship::Ship(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Ship::advance(int phase)
{
    if(phase == 0)
    {
        if(y() == 600)
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
                if(object->getType() == GameObjectType::LandType)
                {
                    transform.rotate(180, Qt::YAxis);
                    this->setTransform(transform);
                    speedX = -speedX;
                }
                else if(object->getType() == GameObjectType::PlaneType ||
                        object->getType() == GameObjectType::BulletType
                       )
                {
                    if(!isDestroyed())
                        emit addPoints(30);
                    destroy();

                    return;
                }
            }
        }
        moveBy(speedX, speedY);
    }
}

GameObjectType Ship::getType()
{
    return GameObjectType::ShipType;
}
