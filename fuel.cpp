#include "fuel.h"

Fuel::Fuel(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
{
    mediaPlayer->setMedia(QUrl("qrc:/music/sounds/explosion.wav"));
}

void Fuel::advance(int phase)
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
                    if(typeid(*(collidingItems[i])) == typeid(Bullet))
                    {
                        emit addPoints(80);
                        deleteObject();
                        mediaPlayer->play();
                        dynamic_cast<BaseGameObject *>(collidingItems[i])->deleteObject();
                        return;
                    }
                }
            }
        }
        moveBy(speedX, speedY);
    }
}
