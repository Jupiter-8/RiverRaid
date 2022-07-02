#include "land.h"

Land::Land(qreal x, qreal y, quint8 speedX, quint8 speedY, const QPixmap &pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent), m_isGameOver(false)
{
}

void Land::advance(int phase)
{
    if(phase == 0 && y() < -10 && !m_isGameOver)
    {
        moveBy(m_speedX, m_speedY);
    }
    if(y() > -50 && !m_isGameOver)
    {
        m_isGameOver = true;
        emit playSound(QUrl("qrc:/music/sounds/game_end.wav"), 30);
        emit gameOver(QString("  You have won!"));
    }
}
