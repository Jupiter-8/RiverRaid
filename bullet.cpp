#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, quint8 speedX, quint8 speedY, const QPixmap &pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent)
{
    m_mediaPlayer = new QMediaPlayer(this->scene());
    m_mediaPlayer->setVolume(10);
    m_mediaPlayer->setMedia(QUrl("qrc:/music/sounds/gun_shoot.wav"));
    m_mediaPlayer->play();
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
        moveBy(m_speedX, m_speedY);
    }
}
