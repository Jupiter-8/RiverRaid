#ifndef BASEGAMEOBJECT_H
#define BASEGAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QTransform>
#include <QUrl>

class BaseGameObject : public QObject, public QGraphicsPixmapItem
{  
    Q_OBJECT

public:
    BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY,
                   const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    void setSpeedX(quint8 value);
    void setSpeedY(quint8 value);
    quint8 getSpeedX() const;
    quint8 getSpeedY() const;
    void deleteObject();

protected:
    qint8 m_speedX;
    qint8 m_speedY;

signals:
    void addPoints(quint32 points);
    void playSound(const QUrl &media, int volume);
};

#endif // BASEGAMEOBJECT_H
