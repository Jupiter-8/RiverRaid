#include "land.h"

Land::Land(qreal x, qreal y, QGraphicsItem *parent, QPixmap pixmap)
    : BaseGameObject(x, y, pixmap, parent)
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
    return GameObjectType::land;
}
