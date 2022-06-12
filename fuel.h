#ifndef FUEL_H
#define FUEL_H

#include "basegameobject.h"

class Fuel : public BaseGameObject
{
    Q_OBJECT

public:
    Fuel(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
           QPixmap pixmap = QPixmap(":/images/models/fuel.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // FUEL_H
