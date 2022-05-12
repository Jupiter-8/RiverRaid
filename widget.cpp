#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , running(false)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);

    Land * land = new Land(0, -4400, 15);
    scene->addItem(land);

    River * river = new River(0, -4400, 15);
    scene->addItem(river);

    Plane * plane = new Plane(350, 490);
    plane->setScale(0.5);
    scene->addItem(plane);

    Ship * ship = new Ship(150, 20, 15);
    scene->addItem(ship);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(plane, &Plane::crash, this, &Widget::stopGame);

    setFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initialize()
{

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_P)
    {
        timer->stop();
    }
    if(key == Qt::Key_S)
    {
        timer->start(60);
    }
}

void Widget::stopGame()
{
    timer->stop();
}

