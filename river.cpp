#include "river.h"

River::River(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
{
}

void River::advance(int phase)
{
    if(phase == 0 && y() < -10)
    {
         moveBy(speedX, speedY);
    }
}
