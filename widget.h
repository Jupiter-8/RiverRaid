#ifndef WIDGET_H
#define WIDGET_H

#include "plane.h"
#include "land.h"
#include "river.h"
#include "ship.h"
#include "enemyplane.h"
#include "helicopter.h"
#include "bridge.h"
#include "fuel.h"

#include <QGraphicsScene>
#include <QWidget>
#include <QPolygonF>
#include <QTimer>
#include <QSet>
#include <QEvent>
#include <QDebug>
#include <QKeyEvent>
#include <QTransform>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initializeScene();

public slots:
    void advance();
    void stopGame();
    void addPoints(quint32 points);

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    bool running;
    QSet<int> pressedKeys;
    Plane *plane;
    quint16 points;
    quint8 speedY;

    bool eventFilter(QObject *object, QEvent *event);
    void changeObjectsYSpeed(bool direction);
};
#endif // WIDGET_H
