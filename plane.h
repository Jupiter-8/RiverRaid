#ifndef PLANE_H
#define PLANE_H

#include "basegameobject.h"
#include "fuel.h"
#include "ship.h"
#include "land.h"
#include "enemyplane.h"
#include "helicopter.h"
#include "bridge.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>

class Plane : public BaseGameObject
{
    Q_OBJECT

private:
    quint32 fuelAmount;
    bool isRefuelling;
    QMediaPlayer *mediaPlayer2;

public:
    Plane(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
          QPixmap pixmap = QPixmap(":/images/models/plane.png"), QGraphicsItem *parent = nullptr);

    void advance(int phase);
    uint getFuelAmount();

signals:
    void gameOver(QString message);
};

#endif // PLANE_H
