#ifndef PLANE_H
#define PLANE_H

#include "basegameobject.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>

class Plane : public BaseGameObject
{
    Q_OBJECT

private:
    uint fuelAmount;
    bool isRefuelling;

public:
    Plane(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
          QPixmap pixmap = QPixmap(":/images/models/plane.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
    uint getFuelAmount();

signals:
    void crash();
    void noFuel();
};

#endif // PLANE_H
