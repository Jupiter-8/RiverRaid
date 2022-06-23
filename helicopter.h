#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "basegameobject.h"
#include "land.h"
#include "bullet.h"

#include <QTransform>

class Helicopter : public BaseGameObject
{
    Q_OBJECT

private:
    QTransform transform;

public:
    Helicopter(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
           QPixmap pixmap = QPixmap(":/images/models/helicopter_1.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
};

#endif // HELICOPTER_H
