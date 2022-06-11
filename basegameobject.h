#ifndef BASEGAMEOBJECT_H
#define BASEGAMEOBJECT_H

#include "gameobjecttype.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QTransform>
#include <QTimer>
#include <QDebug>

class BaseGameObject : public QObject, public QGraphicsPixmapItem
{  
public:
    BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform, QPixmap pixmap, QGraphicsItem *parent = nullptr);

    virtual GameObjectType getType() = 0;
    virtual void destroy() = 0;
    void setSpeedX(quint8 value);
    bool isDestroyed();

protected:
    qint8 speedX;
    qint8 speedY;
    QTransform transform;
    bool destroyed;
    QTimer *timer;

protected slots:
    void changePixmap(QString path);
    void deleteObject();
};



#endif // BASEGAMEOBJECT_H
