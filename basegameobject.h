#ifndef BASEGAMEOBJECT_H
#define BASEGAMEOBJECT_H

#include "gameobjecttype.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>

class BaseGameObject : public QGraphicsPixmapItem
{
public:
    BaseGameObject(qreal x, qreal y, quint8 speed, QPixmap pixmap, QGraphicsItem *parent = nullptr);

    virtual GameObjectType getType() = 0;
    void setSpeed(quint8 value);

protected:
    qint8 speed;
};



#endif // BASEGAMEOBJECT_H
