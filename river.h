#ifndef RIVER_H
#define RIVER_H

#include "basegameobject.h"

class River : public BaseGameObject
{
public:
    River(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
          QPixmap pixmap = QPixmap(":/images/models/river.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // RIVER_H
