#ifndef RIVER_H
#define RIVER_H

#include "basegameobject.h"

class River : public BaseGameObject
{
public:
    River(qreal x, qreal y, quint8 speed = 0, QPixmap pixmap = QPixmap(":/images/models/river.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // RIVER_H
