#include "widget.h"
#include "ui_widget.h"
#include "bullet.h"
#include "mainmenu.h"
#include "objectdescription.h"
#include "objecttype.h"

#include <QDebug>

Widget::Widget(QApplication *app, QWidget *parent)
    : QWidget(parent)
    , m_ui(new Ui::Widget)
    , m_scene(new QGraphicsScene(0, 0, 800, 600, this))
    , m_timer(new QTimer(this))
    , m_plane(new Plane(360, 490, 0, 1))
    , m_points(0)
    , m_speedY(1)
    , m_app(app)
{
    m_ui->setupUi(this);
    initializeScene();
}

Widget::~Widget()
{
    delete m_ui;
}

void Widget::initializeScene()
{
    m_ui->graphicsView->setScene(m_scene);

    connect(m_timer, &QTimer::timeout, m_scene, &QGraphicsScene::advance);
    connect(m_timer, &QTimer::timeout, this, &Widget::advance);

    Land * land = new Land(0, -9400, 0, m_speedY);
    m_scene->addItem(land);
    connect(land, &Land::gameOver, this, &Widget::stopGame);
    connect(land, &BaseGameObject::playSound, this, &Widget::playSound);

    River * river = new River(0, -9400, 0, m_speedY);
    m_scene->addItem(river);

    QList<ObjectDescription> objects = QList<ObjectDescription>
    {
        ObjectDescription(160, -150,  1, m_speedY, ObjectType::SHIP),
        ObjectDescription(210, -3000, 1, m_speedY, ObjectType::SHIP),
        ObjectDescription(220, -1800, 1, m_speedY, ObjectType::SHIP),
        ObjectDescription(280, -2400, 1, m_speedY, ObjectType::SHIP),
        ObjectDescription(280, -5500, 1, m_speedY, ObjectType::SHIP),
        ObjectDescription(280, -7500, 1, m_speedY, ObjectType::SHIP),
        ObjectDescription(280, -8100, 1, m_speedY, ObjectType::SHIP),

        ObjectDescription(210, 0,     -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(270, -450,  -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(210, -600,  -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(260, -4200, -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(300, -8700, -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(290, -5000, -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(290, -1600, -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(230, -2500, -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(230, -6500, -1, m_speedY, ObjectType::HELICOPTER),
        ObjectDescription(230, -6900, -1, m_speedY, ObjectType::HELICOPTER),

        ObjectDescription(800, -3600, -3, m_speedY, ObjectType::ENEMYPLANE),
        ObjectDescription(800, -8000, -3, m_speedY, ObjectType::ENEMYPLANE),

        ObjectDescription(360, -1050, 0, 1, ObjectType::FUEL),
        ObjectDescription(250, -5800, 0, 1, ObjectType::FUEL),

        ObjectDescription(300, -3529, 0, m_speedY, ObjectType::BRIDGE),
        ObjectDescription(300, -8529, 0, m_speedY, ObjectType::BRIDGE),
        ObjectDescription(300, -4535, 0, m_speedY, ObjectType::BRIDGE)
    };

    for(auto &obj : objects)
    {
        BaseGameObject *object = nullptr;
        switch(obj.m_type)
        {
            case ObjectType::SHIP:
                object = new Ship(obj.m_x, obj.m_y, obj.m_speedX, obj.m_speedY);
                break;
            case ObjectType::HELICOPTER:
                object = new Helicopter(obj.m_x, obj.m_y, obj.m_speedX, obj.m_speedY);
                object->setScale(0.7);
                break;
            case ObjectType::ENEMYPLANE:
                object = new EnemyPlane(obj.m_x, obj.m_y, obj.m_speedX, obj.m_speedY);
                object->setScale(0.7);
                break;
            case ObjectType::FUEL:
                object = new Fuel(obj.m_x, obj.m_y, obj.m_speedX, obj.m_speedY);
                object->setScale(0.7);
                break;
            case ObjectType::BRIDGE:
                object = new Bridge(obj.m_x, obj.m_y, obj.m_speedX, obj.m_speedY);
                break;
            default:
                break;
        }

        m_scene->addItem(object);
        connect(object, &BaseGameObject::addPoints, this, &Widget::addPoints);
        connect(object, &BaseGameObject::playSound, this, &Widget::playSound);
    }

    m_plane->setScale(0.5);
    m_scene->addItem(m_plane);
    connect(m_plane, &Plane::gameOver, this, &Widget::stopGame);
    connect(m_plane, &Plane::playSound, this, &Widget::playSound);

    m_scene->setFocus();
    m_scene->installEventFilter(this);

    m_timer->start(10);
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
        Widget *widget = new Widget(m_app);
        widget->show();
        this->destroy();
    }
    else if(msgBox.clickedButton() == showMenuBtn)
    {
        closeEvent(nullptr);
    }
}

void Widget::advance()
{
    quint32 fuelAmount = m_plane->getFuelAmount() / 100;
    m_ui->fuelLabel2->setText(QString::number(fuelAmount) + " %");
    if(fuelAmount < 20)
    {
        m_ui->fuelLabel2->setStyleSheet("color: red;");
    }
    else
    {
        m_ui->fuelLabel2->setStyleSheet("color: #e8e85c;");
    }
}

void Widget::stopGame(const QString &message)
{
    m_timer->stop();
    QGraphicsTextItem *text = new QGraphicsTextItem();
    text->setDefaultTextColor(QColor(232, 232, 92));
    text->setFont(QFont("Visitor TT1 BRK", 60));
    text->setPos(5, 200);
    text->setPlainText(message);
    m_scene->addItem(text);
    showGameOverDialog(message);
}

void Widget::addPoints(quint32 value)
{
    m_points += value;
    m_ui->pointsLabel2->setText(QString::number(m_points));
}

void Widget::playSound(const QUrl &media, int volume)
{
    QMediaPlayer *mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(media);
    mediaPlayer->setVolume(volume);
    mediaPlayer->play();
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        m_pressedKeys += ((QKeyEvent*)event)->key();
        if(m_pressedKeys.contains(Qt::Key_Left) && m_plane->x() > 0)
        {
            m_plane->setX(m_plane->x() - 20);
        }
        if(m_pressedKeys.contains(Qt::Key_Right) && m_plane->x() < 711)
        {
            m_plane->setX(m_plane->x() + 20);
        }
        if(m_pressedKeys.contains(Qt::Key_Up))
        {
            changeObjectsYSpeed(true);
        }
        if(m_pressedKeys.contains(Qt::Key_Down))
        {
            changeObjectsYSpeed(false);
        }
        if(m_pressedKeys.contains(Qt::Key_Space))
        {
            Bullet * bullet = new Bullet(m_plane->x() + 23, m_plane->y() - 15, 0, -12);
            bullet->setScale(0.5);
            m_scene->addItem(bullet);
        }
    }
    else if(event->type() == QEvent::KeyRelease)
    {
        m_pressedKeys -= ((QKeyEvent*)event)->key();
    }

    return false;
}

void Widget::changeObjectsYSpeed(bool direction)
{
    if(direction && m_speedY < 5)
    {
        m_speedY += 1;
    }
    else if(!direction && m_speedY > 1)
    {
        m_speedY -= 1;
    }

    QList<QGraphicsItem *> objects = m_scene->items();
    for(int i = 0; i < objects.size(); i++)
    {
        if(typeid(*(objects[i])) != typeid(Bullet))
        {
            dynamic_cast<BaseGameObject *>(objects[i])->setSpeedY(m_speedY);
        }
    }

    m_ui->speedLabel2->setText(QString::number(m_speedY));
}

void Widget::closeEvent(QCloseEvent *event)
{
    m_timer->stop();
    MainMenu *menu = new MainMenu(m_app);
    QObject::connect(menu, &MainMenu::quitGame, m_app, &QApplication::quit);
    menu->show();
    this->destroy();
}
