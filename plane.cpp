#include "plane.h"
#include "bullet.h"

Plane::Plane(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent), fuelAmount(quint32(10000)), isRefuelling(false)
{
    player = new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/music/sounds/crash.mp3"));
}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!isRefuelling && fuelAmount - (quint32)(speedY * 2) >= (quint32)(speedY * 2))
            fuelAmount -= speedY * 2;
        else if(!isRefuelling && fuelAmount - (quint32)(speedY * 2) < (quint32)(speedY * 2))
            emit noFuel();

        QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
        if(!collidingItems.empty())
        {
            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(typeid(*(collidingItems[i])) == typeid(Land) ||
                   typeid(*(collidingItems[i])) == typeid(Ship) ||
                   typeid(*(collidingItems[i])) == typeid(EnemyPlane) ||
                   typeid(*(collidingItems[i])) == typeid(Bridge) ||
                   typeid(*(collidingItems[i])) == typeid(Helicopter)
                )
                {
                    emit crash();
                    changePixmap(":/images/models/plane_crashed.png");
                    player->play();
                }
                else if(typeid(*(collidingItems[i])) == typeid(Fuel))
                {
                    isRefuelling = true;
                    if(fuelAmount + 200 <= 9800)
                        fuelAmount += 200;
                    else
                        fuelAmount += 10000 - fuelAmount;
                }
                isRefuelling = false;
            }
        }
    }
}

quint32 Plane::getFuelAmount()
{
    return fuelAmount;
}
