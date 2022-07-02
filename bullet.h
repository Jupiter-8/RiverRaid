#ifndef BULLET_H
#define BULLET_H

#include "basegameobject.h"

#include <QMediaPlayer>

class Bullet : public BaseGameObject
{
    Q_OBJECT

public:
    Bullet(qreal x, qreal y, quint8 speedX = 0, quint8 speedY = 0,
           const QPixmap &pixmap = QPixmap(":/images/models/bullet.png"), QGraphicsItem *parent = nullptr);

private:
    QMediaPlayer *m_mediaPlayer;

private slots:
    void advance(int phase);
};

#endif // BULLET_H
