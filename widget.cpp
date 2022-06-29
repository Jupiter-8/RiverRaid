#include "widget.h"
#include "ui_widget.h"
#include "bullet.h"
#include "mainmenu.h"

#include <QDebug>

Widget::Widget(QApplication *app, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , scene(new QGraphicsScene(0, 0, 800, 600, this))
    , timer(new QTimer(this))
    , running(false)
    , plane(new Plane(360, 490, 0, 1))
    , points(0)
    , speedY(1)
    , app(app)
{
    ui->setupUi(this);
    initializeScene();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeScene()
{
    ui->graphicsView->setScene(scene);

    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &Widget::advance);

    Land * land = new Land(0, -9400, 0, speedY);
    scene->addItem(land);
    connect(land, &Land::gameOver, this, &Widget::stopGame);

    River * river = new River(0, -9400, 0, speedY);
    scene->addItem(river);

    Ship * ship1 = new Ship(160, -150, 1, speedY);
    scene->addItem(ship1);
    connect(ship1, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Ship * ship2 = new Ship(210, -3000, 1, speedY);
    scene->addItem(ship2);
    connect(ship2, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Ship * ship3 = new Ship(220, -1800, 1, speedY);
    scene->addItem(ship3);
    connect(ship3, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Ship * ship4 = new Ship(280, -2400, 1, speedY);
    scene->addItem(ship4);
    connect(ship4, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Ship * ship5 = new Ship(280, -5500, 1, speedY);
    scene->addItem(ship5);
    connect(ship5, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Ship * ship6 = new Ship(280, -7500, 1, speedY);
    scene->addItem(ship6);
    connect(ship6, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Ship * ship7 = new Ship(280, -8100, 1, speedY);
    scene->addItem(ship7);
    connect(ship7, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter1 = new Helicopter(210, 0, -1, speedY);
    helicopter1->setScale(0.7);
    scene->addItem(helicopter1);
    connect(helicopter1, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter2 = new Helicopter(270, -450, -1, speedY);
    helicopter2->setScale(0.7);
    scene->addItem(helicopter2);
    connect(helicopter2, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter3 = new Helicopter(210, -600, -1, speedY);
    helicopter3->setScale(0.7);
    scene->addItem(helicopter3);
    connect(helicopter3, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter4 = new Helicopter(260, -4200, -1, speedY);
    helicopter4->setScale(0.7);
    scene->addItem(helicopter4);
    connect(helicopter4, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter5 = new Helicopter(300, -8700, -1, speedY);
    helicopter5->setScale(0.7);
    scene->addItem(helicopter5);
    connect(helicopter5, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter6 = new Helicopter(290, -5000, -1, speedY);
    helicopter6->setScale(0.7);
    scene->addItem(helicopter6);
    connect(helicopter6, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter7 = new Helicopter(290, -1600, -1, speedY);
    helicopter7->setScale(0.7);
    scene->addItem(helicopter7);
    connect(helicopter7, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter8 = new Helicopter(230, -2500, -1, speedY);
    helicopter8->setScale(0.7);
    scene->addItem(helicopter8);
    connect(helicopter8, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter9 = new Helicopter(230, -6500, -1, speedY);
    helicopter9->setScale(0.7);
    scene->addItem(helicopter9);
    connect(helicopter9, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Helicopter * helicopter10 = new Helicopter(230, -6900, -1, speedY);
    helicopter10->setScale(0.7);
    scene->addItem(helicopter10);
    connect(helicopter10, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Fuel * fuel1 = new Fuel(360, -1050, 0, 1);
    fuel1->setScale(0.7);
    scene->addItem(fuel1);
    connect(fuel1, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Fuel * fuel2 = new Fuel(250, -5800, 0, 1);
    fuel2->setScale(0.7);
    scene->addItem(fuel2);
    connect(fuel2, &BaseGameObject::addPoints, this, &Widget::addPoints);

    EnemyPlane * enemyPlane1 = new EnemyPlane(800, -3600, -3, speedY);
    enemyPlane1->setScale(0.7);
    scene->addItem(enemyPlane1);
    connect(enemyPlane1, &BaseGameObject::addPoints, this, &Widget::addPoints);

    EnemyPlane * enemyPlane2 = new EnemyPlane(800, -8000, -3, speedY);
    enemyPlane2->setScale(0.7);
    scene->addItem(enemyPlane2);
    connect(enemyPlane2, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Bridge * bridge1 = new Bridge(300, -3529, 0, speedY);
    scene->addItem(bridge1);
    connect(bridge1, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Bridge * bridge2 = new Bridge(300, -8529, 0, speedY);
    scene->addItem(bridge2);
    connect(bridge2, &BaseGameObject::addPoints, this, &Widget::addPoints);

    Bridge * bridge3 = new Bridge(300, -4535, 0, speedY);
    scene->addItem(bridge3);
    connect(bridge3, &BaseGameObject::addPoints, this, &Widget::addPoints);

    plane->setScale(0.5);
    scene->addItem(plane);
    connect(plane, &Plane::gameOver, this, &Widget::stopGame);

    scene->setFocus();
    scene->installEventFilter(this);
}

void Widget::showGameOverDialog(QString message)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    QPushButton *playAgainBtn = msgBox.addButton("Play again", QMessageBox::NoRole);
    QPushButton *showMenuBtn = msgBox.addButton("Show main menu", QMessageBox::NoRole);
    msgBox.exec();

    if(msgBox.clickedButton() == playAgainBtn)
    {

        Widget *widget = new Widget(app);
        widget->show();
        this->destroy();
    }
    else if(msgBox.clickedButton() == showMenuBtn)
        closeEvent(nullptr);
}

void Widget::advance()
{
    ui->fuelLabel2->setText(QString::number((plane->getFuelAmount() / 100)) + " %");
}

void Widget::stopGame(QString message)
{
    timer->stop();
    QGraphicsTextItem *text = new QGraphicsTextItem();
    text->setDefaultTextColor(QColor(232, 232, 92));
    text->setFont(QFont("Arial", 60));
    text->setPos(20, 200);
    text->setPlainText(message);
    scene->addItem(text);
    showGameOverDialog(message);
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
            timer->start(10);
    }

    if(event->type() == QEvent::KeyPress)
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
    else if(event->type() == QEvent::KeyRelease)
    {
        pressedKeys -= ((QKeyEvent*)event)->key();
    }

    return false;
}

void Widget::changeObjectsYSpeed(bool direction)
{
    if(direction && speedY < 5)
        speedY += 1;
    else if(!direction && speedY > 1)
        speedY -= 1;

    QList<QGraphicsItem *> objects = scene->items();
    for(int i = 0; i < objects.size(); i++)
    {
        if(typeid(*(objects[i])) != typeid(Bullet))
            dynamic_cast<BaseGameObject *>(objects[i])->setSpeedY(speedY);
    }

    ui->speedLabel2->setText(QString::number(speedY));
}

void Widget::closeEvent(QCloseEvent *event)
{
    timer->stop();
    MainMenu *m = new MainMenu(app);
    QObject::connect(m, &MainMenu::quitGame, app, &QApplication::quit);
    m->show();
    this->destroy();
}
