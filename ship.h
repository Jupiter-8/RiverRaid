#ifndef SHIP_H
#define SHIP_H

#include "basegameobject.h"

#include <QGraphicsScene>

class Ship : public BaseGameObject
{
public:
    Ship(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
         QPixmap pixmap = QPixmap(":/images/models/ship.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // SHIP_H
