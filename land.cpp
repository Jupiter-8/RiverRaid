#include "land.h"

Land::Land(qreal x, qreal y, quint8 speedX, quint8 speedY, QPixmap pixmap, QGraphicsItem *parent)
    : BaseGameObject(x, y, speedX, speedY, pixmap, parent), isGameOver(false)
{
}

void Land::advance(int phase)
{
    if(phase == 0 && y() < -10 && !isGameOver)
        moveBy(speedX, speedY);
    if(y() > -50 && !isGameOver)
    {
        isGameOver = true;
        emit playSound(QUrl("qrc:/music/sounds/game_end.wav"), 30);
        emit gameOver(QString("     You have won!"));
    }
}
