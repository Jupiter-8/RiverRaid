#ifndef BRIDGE_H
#define BRIDGE_H

#include "basegameobject.h"
#include "bullet.h"

class Bridge : public BaseGameObject
{
    Q_OBJECT

public:
    Bridge(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
           QPixmap pixmap = QPixmap(":/images/models/bridge.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
};

#endif // BRIDGE_H
