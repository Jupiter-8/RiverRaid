#ifndef BULLET_H
#define BULLET_H

#include "basegameobject.h"

class Bullet : public BaseGameObject
{
public:
    Bullet(qreal x, qreal y, quint8 speed = 0, QPixmap pixmap = QPixmap(":/images/models/bullet.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // BULLET_H
