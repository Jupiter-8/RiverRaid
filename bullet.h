#ifndef BULLET_H
#define BULLET_H

#include "basegameobject.h"

class Bullet : public BaseGameObject
{
public:
    Bullet(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
           QPixmap pixmap = QPixmap(":/images/models/bullet.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // BULLET_H
