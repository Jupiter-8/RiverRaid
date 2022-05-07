#include "river.h"

River::River(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speed, pixmap, parent)
{

}

void River::advance(int phase)
{
    if(phase == 0)
    {
        moveBy(0, speed);
    }
}

GameObjectType River::getType()
{
    return GameObjectType::RiverType;
}
