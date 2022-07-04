#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "basegameobject.h"
#include "bullet.h"
#include "land.h"

#include <QTransform>

class Helicopter : public BaseGameObject
{
    Q_OBJECT

public:
    Helicopter(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
           const QPixmap &pixmap = QPixmap(":/images/models/helicopter_1.png"), QGraphicsItem *parent = nullptr);

private:
    QTransform *m_transform;

private slots:
    void advance(int phase);
};

#endif // HELICOPTER_H
