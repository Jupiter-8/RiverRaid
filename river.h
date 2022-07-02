#ifndef RIVER_H
#define RIVER_H

#include "basegameobject.h"

class River : public BaseGameObject
{
    Q_OBJECT

public:
    River(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
          const QPixmap &pixmap = QPixmap(":/images/models/river.png"), QGraphicsItem *parent = nullptr);

private slots:
    void advance(int phase);
};

#endif // RIVER_H
