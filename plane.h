#ifndef PLANE_H
#define PLANE_H

#include "basegameobject.h"
#include "bridge.h"
#include "enemyplane.h"
#include "fuel.h"
#include "helicopter.h"
#include "land.h"
#include "ship.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QString>

class Plane : public BaseGameObject
{
    Q_OBJECT

public:
    Plane(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
          const QPixmap &pixmap = QPixmap(":/images/models/plane.png"), QGraphicsItem *parent = nullptr);

    uint getFuelAmount() const;

private:
    quint32 m_fuelAmount;
    bool m_isRefueling;

private slots:
    void advance(int phase);

signals:
    void gameOver(const QString &message);
};

#endif // PLANE_H
