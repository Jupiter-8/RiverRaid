#ifndef LAND_H
#define LAND_H

#include "basegameobject.h"

class Land : public BaseGameObject
{
    Q_OBJECT
public:
    Land(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
         QPixmap pixmap = QPixmap(":/images/models/land.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
};

#endif // LAND_H
