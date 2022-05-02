#ifndef LAND_H
#define LAND_H

#include "basegameobject.h"

class Land : public BaseGameObject
{
public:
    Land(qreal x, qreal y, QGraphicsItem *parent = nullptr, QPixmap pixmap = QPixmap(":/images/models/land.png"));

    void advance(int phase);
    GameObjectType getType();
};

#endif // LAND_H
