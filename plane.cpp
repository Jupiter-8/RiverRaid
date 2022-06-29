#include "plane.h"
#include "bullet.h"
#include "widget.h"

Plane::Plane(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent), fuelAmount(quint32(10000)), isRefuelling(false)
{
    mediaPlayer->setMedia(QUrl("qrc:/music/sounds/crash.mp3"));
    mediaPlayer2 = new QMediaPlayer(this->scene());
    mediaPlayer2->setMedia(QUrl("qrc:/music/sounds/refuel.wav"));
}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!isRefuelling && fuelAmount - (quint32)(speedY * 2) >= (quint32)(speedY * 2))
            fuelAmount -= speedY * 2;
        else if(!isRefuelling && fuelAmount - (quint32)(speedY * 2) < (quint32)(speedY * 2))
        {
            emit gameOver(QString("        Out of fuel!"));
        }

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
                    changePixmap(":/images/models/plane_crashed.png");
                    mediaPlayer->play();
                    emit gameOver(QString("  You have crashed!  "));
                }
                else if(typeid(*(collidingItems[i])) == typeid(Fuel))
                {
                    if(!isRefuelling)
                    {
                        isRefuelling = true;
                        mediaPlayer2->play();
                    }

                    if(fuelAmount + 200 <= 9800)
                        fuelAmount += 200;
                    else
                        fuelAmount += 10000 - fuelAmount;
                }
                else
                    isRefuelling = false;
            }
        }
    }
}

quint32 Plane::getFuelAmount()
{
    return fuelAmount;
}
