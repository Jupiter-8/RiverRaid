#ifndef SHIP_H
#define SHIP_H

#include "basegameobject.h"
#include "land.h"
#include "bullet.h"
#include <QTransform>

class Ship : public BaseGameObject
{
    Q_OBJECT

public:
    Ship(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
         QPixmap pixmap = QPixmap(":/images/models/ship.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);

};

#endif // SHIP_H
