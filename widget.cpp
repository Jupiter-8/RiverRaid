#include "widget.h"
#include "ui_widget.h"
#include "bullet.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , running(false)
    , plane(new Plane(360, 490, 0, 1))
    , points(0)
    , speedY(1)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &Widget::advance);

    Land * land = new Land(0, -4400, 0, speedY);
    scene->addItem(land);

    River * river = new River(0, -4400, 0, speedY);
    scene->addItem(river);

    plane->setScale(0.5);
    scene->addItem(plane);

    Bridge * bridge = new Bridge(300, -3530, 0, speedY);
    scene->addItem(bridge);

    Ship * ship1 = new Ship(160, -250, 1, speedY);
    scene->addItem(ship1);

    Ship * ship3 = new Ship(160, -1750, 1, speedY);
    scene->addItem(ship3);

    EnemyPlane * enemyPlane = new EnemyPlane(800, 300, -3, speedY);
    enemyPlane->setScale(0.7);
    scene->addItem(enemyPlane);

    Helicopter * helicopter = new Helicopter(210, -570, -1, speedY);
    helicopter->setScale(0.7);
    scene->addItem(helicopter);

    Fuel * fuel = new Fuel(360, -2500, 0, 1);
    fuel->setScale(0.7);
    scene->addItem(fuel);

    connect(plane, &Plane::crash, this, &Widget::stopGame);
    connect(plane, &Plane::noFuel, this, &Widget::stopGame);


      connect(ship1, &BaseGameObject::addPoints, this, &Widget::addPoints);
      connect(enemyPlane, &BaseGameObject::addPoints, this, &Widget::addPoints);
      connect(helicopter, &BaseGameObject::addPoints, this, &Widget::addPoints);
      connect(bridge, &BaseGameObject::addPoints, this, &Widget::addPoints);
      connect(fuel, &BaseGameObject::addPoints, this, &Widget::addPoints);

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

void Widget::advance()
{
    ui->fuelLabel2->setText(QString::number((plane->getFuelAmount() / 100)) + " %");
}

void Widget::stopGame()
{
    timer->stop();
    qDebug() << "Game Over";
}

void Widget::addPoints(quint32 value)
{
    points += value;
    ui->pointsLabel2->setText(QString::number(points));
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
            timer->start(1);
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
            Bullet * bullet = new Bullet(plane->x() + 23, plane->y() - 15, 0, -12);
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
    if(direction && speedY < 20)
        speedY += 1;
    else if(!direction && speedY > 1)
        speedY -= 1;

    QList<QGraphicsItem *> objects = scene->items();
    for(int i = 0; i < objects.size(); i++)
    {
        if(typeid(*(objects[i])) != typeid(Bullet))
        {
            static_cast<BaseGameObject *>(objects[i])->setSpeedY(speedY);
        }
    }

    ui->speedLabel2->setText(QString::number(speedY));
}

