#include "plane.h"
#include "bullet.h"
#include "widget.h"

Plane::Plane(qreal x, qreal y, quint8 speedX, quint8 speedY, const QPixmap &pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent), m_fuelAmount(quint32(10000)), m_isRefueling(false)
{
}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!m_isRefueling && m_fuelAmount - (quint32)(m_speedY * 2) >= (quint32)(m_speedY * 2))
        {
            m_fuelAmount -= m_speedY * 2;
        }
        else if(!m_isRefueling && m_fuelAmount - (quint32)(m_speedY * 2) < (quint32)(m_speedY * 2))
        {
            emit gameOver(QString(" Out of the fuel!"));
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
                    setPixmap(QPixmap(":/images/models/plane_crashed.png"));
                    emit playSound(QUrl("qrc:/music/sounds/crash.mp3"), 5);
                    emit gameOver(QString("You have crashed!"));
                    return;
                }
                else if(typeid(*(collidingItems[i])) == typeid(Fuel))
                {
                    if(!m_isRefueling)
                    {
                        m_isRefueling = true;
                        emit playSound(QUrl("qrc:/music/sounds/refuel.wav"), 100);
                    }

                    if(m_fuelAmount + 200 <= 9800)
                    {
                        m_fuelAmount += 200;
                    }
                    else
                    {
                        m_fuelAmount += 10000 - m_fuelAmount;
                    }

                    return;
                }
                else
                {
                    m_isRefueling = false;
                }
            }
        }
    }
}

quint32 Plane::getFuelAmount() const
{
    return m_fuelAmount;
}
