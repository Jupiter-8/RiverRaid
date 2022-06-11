#include "bridge.h"

Bridge::Bridge(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Bridge::advance(int phase)
{
    if(phase == 0)
    {
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
                    destroyed = true;
                    speedX = 0;
                    timer->start(1);
                    timer->singleShot(1, this, [this] () { this->changePixmap(":/images/models/bridge_destroyed_1.png"); } );
                    timer->singleShot(250, this, [this] () { this->changePixmap(":/images/models/bridge_destroyed_2.png"); } );
                    timer->singleShot(500, this, [this] () { this->changePixmap(":/images/models/bridge_destroyed_1.png"); } );
                    timer->singleShot(750, this, &Bridge::deleteObject );
                    return;
                }
            }
        }
        moveBy(speedX, speedY);
    }
}

GameObjectType Bridge::getType()
{
    return GameObjectType::BridgeType;
}
