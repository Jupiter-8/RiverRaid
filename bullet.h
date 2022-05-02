#ifndef BULLET_H
#define BULLET_H

#include "basegameobject.h"

class Bullet : public BaseGameObject
{
public:
    Bullet(qreal x, qreal y, QGraphicsItem *parent = nullptr, QPixmap pixmap = QPixmap(":/images/models/bullet.png"));

    void advance(int phase);
    GameObjectType getType();
};

#endif // BULLET_H
