#include "plane.h"
#include "bullet.h"

Plane::Plane(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent), fuelAmount(10000), isRefuelling(false)
{
    player = new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/music/sounds/crash.mp3"));
}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!isRefuelling && fuelAmount - speedY > 0)
            fuelAmount -= speedY;
        else if(fuelAmount - speedY <= 0)
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
                    fuelAmount += 15;
                }
                isRefuelling = false;
            }
        }
    }
}

uint Plane::getFuelAmount()
{
    return fuelAmount;
}
