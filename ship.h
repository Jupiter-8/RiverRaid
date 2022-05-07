#ifndef SHIP_H
#define SHIP_H

#include "basegameobject.h"

class Ship : public BaseGameObject
{
public:
    Ship(qreal x, qreal y, quint8 speed = 0, QPixmap pixmap = QPixmap(":/images/models/ship.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // SHIP_H
