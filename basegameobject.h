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
    BaseGameObject(qreal x, qreal y, quint8 speedX, quint8 speedY,
                   QPixmap pixmap, QGraphicsItem *parent = nullptr);

    void setSpeedX(quint8 value);
    void setSpeedY(quint8 value);
    quint8 getSpeedX();
    quint8 getSpeedY();
    void deleteObject();

protected:
    qint8 speedX;
    qint8 speedY;
    QTimer *timer;
    QMediaPlayer *mediaPlayer;

protected slots:
    void changePixmap(QString path);

signals:
    void addPoints(quint32 points);
};



#endif // BASEGAMEOBJECT_H
