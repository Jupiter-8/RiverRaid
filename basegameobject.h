#ifndef BASEGAMEOBJECT_H
#define BASEGAMEOBJECT_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QTransform>
#include <QTimer>
#include <QDebug>
#include <QMediaPlayer>

class BaseGameObject : public QObject, public QGraphicsPixmapItem
{  
    Q_OBJECT

public:
    BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY, QTransform transform,
                   QPixmap pixmap, QGraphicsItem *parent = nullptr);

    void destroy(qreal scale = 1.0);
    void setSpeedX(quint8 value);
    void setSpeedY(quint8 value);
    quint8 getSpeedX();
    quint8 getSpeedY();
    bool isDestroyed();

protected:
    qint8 speedX;
    qint8 speedY;
    QTransform transform;
    bool destroyed;
    QTimer *timer;
    QMediaPlayer *player;

public slots:
    void deleteObject();

protected slots:
    void changePixmap(QString path);

signals:
    void addPoints(quint32 points);
};



#endif // BASEGAMEOBJECT_H
