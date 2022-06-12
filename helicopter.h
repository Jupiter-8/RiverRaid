#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "basegameobject.h"

class Helicopter : public BaseGameObject
{
    Q_OBJECT

public:
    Helicopter(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
           QPixmap pixmap = QPixmap(":/images/models/helicopter_1.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // HELICOPTER_H
