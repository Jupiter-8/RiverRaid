#ifndef FUEL_H
#define FUEL_H

#include "basegameobject.h"
#include "bullet.h"

class Fuel : public BaseGameObject
{
    Q_OBJECT

public:
    Fuel(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
           const QPixmap &pixmap = QPixmap(":/images/models/fuel.png"), QGraphicsItem *parent = nullptr);

private slots:
    void advance(int phase);
};

#endif // FUEL_H
