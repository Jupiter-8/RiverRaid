#ifndef PLANE_H
#define PLANE_H

#include "basegameobject.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>

class Plane : public BaseGameObject
{
public:
    Plane(qreal x, qreal y, quint8 speed = 0, QPixmap pixmap = QPixmap(":/images/models/plane.png"), QGraphicsItem *parent = nullptr);

    void keyPressEvent(QKeyEvent *event);
    void advance(int phase);
    GameObjectType getType();
};

#endif // PLANE_H
