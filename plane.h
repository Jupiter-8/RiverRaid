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
    quint32 fuel;

public:
    Plane(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
          QPixmap pixmap = QPixmap(":/images/models/plane.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();

signals:
    void crash();
};

#endif // PLANE_H
