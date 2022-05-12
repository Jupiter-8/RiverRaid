#include "plane.h"
#include "bullet.h"

Plane::Plane(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speed, pixmap, parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Plane::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left && x() > 0)
    {
        setX(x() - 20);
    }
    if(event->key() == Qt::Key_Right && x()< 711)
    {
        setX(x() + 20);
    }
    if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(x() + 23, x() - 15);
        bullet->setScale(0.5);
        scene()->addItem(bullet);
    }
}

void Plane::advance(int phase)
{
    if(phase == 0)
    {
        if(!scene()->collidingItems(this).empty())
        {
            QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);

            for(int i = 0; i < collidingItems.size(); i++)
            {
                BaseGameObject *object = static_cast<BaseGameObject *>(collidingItems[i]);
                if(object->getType() == GameObjectType::LandType)
                    emit crash();
            }
        }
    }
}

GameObjectType Plane::getType()
{
    return GameObjectType::PlaneType;
}
