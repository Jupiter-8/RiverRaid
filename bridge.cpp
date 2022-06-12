#include "bridge.h"

Bridge::Bridge(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Bridge::advance(int phase)
{
    if(phase == 0)
    {
        if(y() < 600 && y() > 0)
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
            if(!collidingItems.empty())
            {
                for(int i = 0; i < collidingItems.size(); i++)
                {
                    if(typeid(*(collidingItems[i])) == typeid(Bullet))
                    {
                        if(!isDestroyed())
                            emit addPoints(500);
                        destroyed = true;
                        speedX = 0;
                        timer->singleShot(1, this, [this] () { this->changePixmap(":/images/models/bridge_destroyed_1.png"); } );
                        timer->singleShot(250, this, [this] () { this->changePixmap(":/images/models/bridge_destroyed_2.png"); } );
                        timer->singleShot(500, this, [this] () { this->changePixmap(":/images/models/bridge_destroyed_1.png"); } );
                        timer->singleShot(750, this, &Bridge::deleteObject );
                        static_cast<BaseGameObject *>(collidingItems[i])->deleteObject();
                        return;
                    }
                }
            }
        }
        moveBy(speedX, speedY);
    }
}
