#ifndef LAND_H
#define LAND_H

#include "basegameobject.h"

class Land : public BaseGameObject
{
public:
    Land(qreal x, qreal y, quint8 speed = 0, QPixmap pixmap = QPixmap(":/images/models/land.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // LAND_H
