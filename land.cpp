#include "land.h"

Land::Land(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
{

}

void Land::advance(int phase)
{
    if(phase == 0 && y() < -10)
    {
        moveBy(speedX, speedY);
    }
    if(y() > -50)
        emit finishGame();
}
