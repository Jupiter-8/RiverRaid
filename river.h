#ifndef RIVER_H
#define RIVER_H

#include "basegameobject.h"

class River : public BaseGameObject
{
public:
    River(qreal x, qreal y, QGraphicsItem *parent = nullptr, QPixmap pixmap = QPixmap(":/images/models/river.png"));

    void advance(int phase);
    GameObjectType getType();
};

#endif // RIVER_H
