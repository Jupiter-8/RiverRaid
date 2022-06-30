#include "bridge.h"

Bridge::Bridge(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
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
                        emit addPoints(500);
                        emit playSound(QUrl("qrc:/music/sounds/explosion.wav"), 5);
                        dynamic_cast<BaseGameObject *>(collidingItems[i])->deleteObject();
                        deleteObject();
                        return;
                    }
                }
            }
        }
        moveBy(speedX, speedY);
    }
}
