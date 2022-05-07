#include "land.h"

Land::Land(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speed, pixmap, parent)
{

}

void Land::advance(int phase)
{
    if(phase == 0)
    {
        moveBy(0, speed);
    }
}

GameObjectType Land::getType()
{
    return GameObjectType::LandType;
}
