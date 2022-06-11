#include "widget.h"
#include "ui_widget.h"
#include "bullet.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , running(false)
    , plane(new Plane(360, 490))
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);

    Land * land = new Land(0, -4400, 0, 1);
    scene->addItem(land);

    River * river = new River(0, -4400, 0, 1);
    scene->addItem(river);

    plane->setScale(0.5);
    scene->addItem(plane);

    Ship * ship1 = new Ship(160, 20, 1, 1);
    scene->addItem(ship1);

    EnemyPlane * enemyPlane = new EnemyPlane(800, 10, -3, 1);
    enemyPlane->setScale(0.7);
    scene->addItem(enemyPlane);

    Helicopter * helicopter = new Helicopter(160, 30, -1, 1);
    helicopter->setScale(0.7);
    scene->addItem(helicopter);


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
            timer->start(10);
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
        if(pressedKeys.contains(Qt::Key_Up))
        {
            changeObjectsYSpeed(true);
        }
        if(pressedKeys.contains(Qt::Key_Down))
        {
            changeObjectsYSpeed(false);
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

void Widget::changeObjectsYSpeed(bool direction)
{
    QList<QGraphicsItem *> objects = scene->items();
    for(int i = 0; i < objects.size(); i++)
    {
        BaseGameObject *object = static_cast<BaseGameObject *>(objects[i]);
        if(object->getType() != GameObjectType::PlaneType && object->getType() != GameObjectType::BulletType)
        {
            if(direction && object->getSpeedY() < 25)
                object->setSpeedY(object->getSpeedY() + 1);
            else if(!direction && object->getSpeedY() > 2)
                object->setSpeedY(object->getSpeedY() - 1);
        }
    }
}

