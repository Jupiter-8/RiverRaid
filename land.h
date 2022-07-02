#ifndef LAND_H
#define LAND_H

#include "basegameobject.h"

class Land : public BaseGameObject
{
    Q_OBJECT

public:
    Land(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
         const QPixmap &pixmap = QPixmap(":/images/models/land.png"), QGraphicsItem *parent = nullptr);

private:
    bool m_isGameOver;

private slots:
    void advance(int phase);

signals:
    void gameOver(const QString &message);
};

#endif // LAND_H
