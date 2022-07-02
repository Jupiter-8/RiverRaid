#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "basegameobject.h"
#include "bullet.h"

class EnemyPlane : public BaseGameObject
{
    Q_OBJECT

public:
    EnemyPlane(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
           const QPixmap &pixmap = QPixmap(":/images/models/enemy_plane.png"), QGraphicsItem *parent = nullptr);

private slots:
    void advance(int phase);
};

#endif // ENEMYPLANE_H
