#ifndef BRIDGE_H
#define BRIDGE_H

#include "basegameobject.h"

class Bridge : public BaseGameObject
{
    Q_OBJECT

public:
    Bridge(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0, QTransform transform = QTransform(),
           QPixmap pixmap = QPixmap(":/images/models/bridge.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    GameObjectType getType();
};

#endif // BRIDGE_H
