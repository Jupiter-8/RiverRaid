#include "widget.h"
#include "ui_widget.h"
#include "plane.h"
#include "land.h"
#include "river.h"

#include <QPolygonF>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);

    Land *land = new Land(0, -4400);
    land->setSpeed(55);
    scene->addItem(land);

    River * river = new River(0, -4400);
    river->setSpeed(55);
    scene->addItem(river);

    Plane *plane = new Plane(350, 490);
    plane->setScale(0.5);
    plane->setSpeed(0);
    scene->addItem(plane);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(60);
}

Widget::~Widget()
{
    delete ui;
}

