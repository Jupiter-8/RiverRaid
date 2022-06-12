#include "ship.h"

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
        else if(y() < 600 && y() > 0)
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
            if(!collidingItems.empty())
            {
                for(int i = 0; i < collidingItems.size(); i++)
                {
                    if(typeid(*(collidingItems[i])) == typeid(Land))
                    {
                        transform.rotate(180, Qt::YAxis);
                        this->setTransform(transform);
                        speedX = -speedX;
                    }
                    if(typeid(*(collidingItems[i])) == typeid(Bullet))
                    {
                        if(!isDestroyed())
                            emit addPoints(30);
                        destroy();
                        static_cast<BaseGameObject *>(collidingItems[i])->deleteObject();
                        return;
                    }
                }
            }
            moveBy(speedX, speedY);
        }
        else
            moveBy(0, speedY);
    }
}
