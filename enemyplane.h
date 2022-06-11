#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "basegameobject.h"

class EnemyPlane : public BaseGameObject
{
public:
    EnemyPlane(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
           QPixmap pixmap = QPixmap(":/images/models/enemy_plane.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // ENEMYPLANE_H
