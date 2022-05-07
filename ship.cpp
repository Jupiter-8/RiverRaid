#include "ship.h"

Ship::Ship(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speed, pixmap, parent)
{

}

void Ship::advance(int phase)
{
    if(phase == 0)
    {
        moveBy(10, speed);
    }
}

GameObjectType Ship::getType()
{
    return GameObjectType::ShipType;
}
