#include "helicopter.h"

Helicopter::Helicopter(qreal x, qreal y, quint8 speedX, quint8 speedY, const QPixmap &pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent), m_transform(new QTransform())
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
                        m_transform->rotate(180, Qt::YAxis);
                        m_transform->translate(-65,0);
                        setTransform(*m_transform);
                        m_speedX = -m_speedX;
                    }
                    else if(typeid(*(collidingItems[i])) == typeid(Bullet))
                    {
                        emit addPoints(60);
                        emit playSound(QUrl("qrc:/music/sounds/explosion.wav"), 7);
                        dynamic_cast<BaseGameObject *>(collidingItems[i])->deleteObject();
                        deleteObject();
                        return;
                    }
                }
            }
            moveBy(m_speedX, m_speedY);
        }
        else
        {
            moveBy(0, m_speedY);
        }
    }
}
