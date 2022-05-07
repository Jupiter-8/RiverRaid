#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
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

    Ship * ship = new Ship(350, 20, 15);
    scene->addItem(ship);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(60);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initialize()
{

}

