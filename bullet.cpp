#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
{
    mediaPlayer = new QMediaPlayer(this->scene());
    mediaPlayer->setVolume(10);
    mediaPlayer->setMedia(QUrl("qrc:/music/sounds/gun_shoot.wav"));
    mediaPlayer->play();
}

void Bullet::advance(int phase)
{
    if(phase == 0)
    {
        if(y() < -10)
        {
            deleteObject();
            return;
        }
        moveBy(speedX, speedY);
    }
}
