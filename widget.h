#ifndef WIDGET_H
#define WIDGET_H

#include "plane.h"
#include "land.h"
#include "river.h"
#include "ship.h"

#include <QGraphicsScene>
#include <QWidget>
#include <QPolygonF>
#include <QTimer>
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initialize();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void stopGame();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    bool running;
};
#endif // WIDGET_H
