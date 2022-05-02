#include "river.h"

River::River(qreal x, qreal y, QGraphicsItem *parent, QPixmap pixmap)
    : BaseGameObject(x, y, pixmap, parent)
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
    return GameObjectType::river;
}
