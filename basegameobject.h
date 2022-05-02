#ifndef BASEGAMEOBJECT_H
#define BASEGAMEOBJECT_H

#include "gameobjecttype.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>

class BaseGameObject : public QGraphicsPixmapItem
{
public:
    BaseGameObject(qreal x, qreal y, QPixmap pixmap, QGraphicsItem *parent = nullptr);

    virtual GameObjectType getType() = 0;
    void setSpeed(quint32 value);

protected:
    qint32 speed;
};



#endif // BASEGAMEOBJECT_H
