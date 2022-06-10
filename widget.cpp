#include "widget.h"
#include "ui_widget.h"
#include "bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTransform>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , running(false)
    , plane(new Plane(360, 490))
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);

    Land * land = new Land(0, -4400, 0, 25);
    scene->addItem(land);

    River * river = new River(0, -4400, 0, 25);
    scene->addItem(river);

    plane->setScale(0.5);
    scene->addItem(plane);

    Ship * ship1 = new Ship(160, 20, 12, 25);
    scene->addItem(ship1);
    //scene->removeItem(ship1);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(plane, &Plane::crash, this, &Widget::stopGame);

    scene->setFocus();
    scene->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initialize()
{

}

void Widget::stopGame()
{
    timer->stop();
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

    if(keyEvent->key() == Qt::Key_P)
    {
            timer->stop();
    }
    else if(keyEvent->key() == Qt::Key_S)
    {
            timer->start(60);
    }

    if(event->type() == QEvent::KeyPress /*&& !keyEvent->isAutoRepeat()*/)
    {
        pressedKeys += ((QKeyEvent*)event)->key();

        if(pressedKeys.contains(Qt::Key_Left) && plane->x() > 0)
        {
            plane->setX(plane->x() - 20);
        }
        if(pressedKeys.contains(Qt::Key_Right) && plane->x() < 711)
        {
            plane->setX(plane->x() + 20);
        }
        if(pressedKeys.contains(Qt::Key_Space))
        {
            Bullet * bullet = new Bullet(plane->x() + 23, plane->y() - 15, 0, -25);
            bullet->setScale(0.5);
            scene->addItem(bullet);
        }
    }
    else if(event->type() == QEvent::KeyRelease /*&& !keyEvent->isAutoRepeat()*/)
    {
        pressedKeys -= ((QKeyEvent*)event)->key();
    }

    return false;
}

