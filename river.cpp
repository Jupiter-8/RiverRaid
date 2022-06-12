#include "river.h"

River::River(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, transform, pixmap, parent)
{

}

void River::advance(int phase)
{
    if(phase == 0)
    {
        moveBy(speedX, speedY);
    }
}
