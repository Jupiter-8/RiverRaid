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
                    destroy();
                    return;
                }
            }
        }
        moveBy(speedX, speedY);
    }
}

void Ship::destroy()
{
    destroyed = true;
    speedX = 0;
    timer->start(30);
    timer->singleShot(1, this, [this] () { this->changePixmap(":/images/models/ship_destroyed_1.png"); } );
    timer->singleShot(250, this, [this] () { this->changePixmap(":/images/models/ship_destroyed_2.png"); } );
    timer->singleShot(500, this, [this] () { this->changePixmap(":/images/models/ship_destroyed_1.png"); } );
    timer->singleShot(750, this, &Ship::deleteObject );
}

GameObjectType Ship::getType()
{
    return GameObjectType::ShipType;
}
