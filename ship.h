#ifndef SHIP_H
#define SHIP_H

#include "basegameobject.h"
#include "bullet.h"
#include "land.h"

#include <QTransform>

class Ship : public BaseGameObject
{
    Q_OBJECT

public:
    Ship(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
         const QPixmap &pixmap = QPixmap(":/images/models/ship.png"), QGraphicsItem *parent = nullptr);

private:
    QTransform m_transform;

private slots:
    void advance(int phase);
};

#endif // SHIP_H
