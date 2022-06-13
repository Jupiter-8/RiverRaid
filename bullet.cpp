#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
{
    player = new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/music/sounds/gun_shoot.wav"));
    player->play();
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
