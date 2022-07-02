#include "widget.h"
#include "ui_widget.h"
#include "bullet.h"
#include "mainmenu.h"
#include "objectdescription.h"
#include "objecttype.h"

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

    QList<ObjectDescription> objects = QList<ObjectDescription>
    {
        ObjectDescription(160, -150,  1, speedY, ObjectType::SHIP),
        ObjectDescription(210, -3000, 1, speedY, ObjectType::SHIP),
        ObjectDescription(220, -1800, 1, speedY, ObjectType::SHIP),
        ObjectDescription(280, -2400, 1, speedY, ObjectType::SHIP),
        ObjectDescription(280, -5500, 1, speedY, ObjectType::SHIP),
        ObjectDescription(280, -7500, 1, speedY, ObjectType::SHIP),
        ObjectDescription(280, -8100, 1, speedY, ObjectType::SHIP),

        ObjectDescription(210, 0,     -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(270, -450,  -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(210, -600,  -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(260, -4200, -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(300, -8700, -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(290, -5000, -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(290, -1600, -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(230, -2500, -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(230, -6500, -1, speedY, ObjectType::HELICOPTER),
        ObjectDescription(230, -6900, -1, speedY, ObjectType::HELICOPTER),

        ObjectDescription(800, -3600, -3, speedY, ObjectType::ENEMYPLANE),
        ObjectDescription(800, -8000, -3, speedY, ObjectType::ENEMYPLANE),

        ObjectDescription(360, -1050, 0, 1, ObjectType::FUEL),
        ObjectDescription(250, -5800, 0, 1, ObjectType::FUEL),

        ObjectDescription(300, -3529, 0, speedY, ObjectType::BRIDGE),
        ObjectDescription(300, -8529, 0, speedY, ObjectType::BRIDGE),
        ObjectDescription(300, -4535, 0, speedY, ObjectType::BRIDGE)
    };

    for(auto &obj : objects)
    {
        BaseGameObject *object = nullptr;
        switch(obj.type)
        {
            case ObjectType::SHIP:
                object = new Ship(obj.x, obj.y, obj.speedX, obj.speedY);
                break;
            case ObjectType::HELICOPTER:
                object = new Helicopter(obj.x, obj.y, obj.speedX, obj.speedY);
                object->setScale(0.7);
                break;
            case ObjectType::ENEMYPLANE:
                object = new EnemyPlane(obj.x, obj.y, obj.speedX, obj.speedY);
                object->setScale(0.7);
                break;
            case ObjectType::FUEL:
                object = new Fuel(obj.x, obj.y, obj.speedX, obj.speedY);
                object->setScale(0.7);
                break;
            case ObjectType::BRIDGE:
                object = new Bridge(obj.x, obj.y, obj.speedX, obj.speedY);
                break;
        }

        scene->addItem(object);
        connect(object, &BaseGameObject::addPoints, this, &Widget::addPoints);
        connect(object, &BaseGameObject::playSound, this, &Widget::playSound);
    }

    plane->setScale(0.5);
    scene->addItem(plane);
    connect(plane, &Plane::gameOver, this, &Widget::stopGame);
    connect(plane, &Plane::playSound, this, &Widget::playSound);

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

void Widget::playSound(QUrl media, int volume)
{
    QMediaPlayer *mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(media);
    mediaPlayer->setVolume(volume);
    mediaPlayer->play();
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
