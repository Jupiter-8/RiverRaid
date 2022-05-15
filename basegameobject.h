#ifndef BASEGAMEOBJECT_H
#define BASEGAMEOBJECT_H

#include "gameobjecttype.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QTransform>

class BaseGameObject : public QObject, public QGraphicsPixmapItem
{  
public:
    BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent = nullptr);

    virtual GameObjectType getType() = 0;
    void setSpeedX(quint8 value);

protected:
    qint8 speedX;
    qint8 speedY;
    QTransform transform;
};



#endif // BASEGAMEOBJECT_H
