#include "helicopter.h"

Helicopter::Helicopter(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void Helicopter::advance(int phase)
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
                        transform.translate(-65,0);
                        setTransform(transform);
                        speedX = -speedX;
                    }
                    else if(typeid(*(collidingItems[i])) == typeid(Bullet))
                    {
                        if(!isDestroyed())
                            emit addPoints(60);
                        destroy(0.4);
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
