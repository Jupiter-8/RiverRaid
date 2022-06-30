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
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QApplication *app, QWidget *parent = nullptr);
    ~Widget();

    void initializeScene();
    void showGameOverDialog(QString message);

public slots:
    void advance();
    void stopGame(QString message);
    void addPoints(quint32 points);
    void playSound(QUrl media, int volume);

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    bool running;
    QSet<int> pressedKeys;
    Plane *plane;
    quint16 points;
    quint8 speedY;
    QApplication *app;

    bool eventFilter(QObject *object, QEvent *event);
    void changeObjectsYSpeed(bool direction);
    void closeEvent(QCloseEvent *event);
};
#endif // WIDGET_H
