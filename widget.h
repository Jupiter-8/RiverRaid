#ifndef WIDGET_H
#define WIDGET_H

#include "bridge.h"
#include "enemyplane.h"
#include "fuel.h"
#include "helicopter.h"
#include "land.h"
#include "plane.h"
#include "river.h"
#include "ship.h"

#include <QApplication>
#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPolygonF>
#include <QPushButton>
#include <QSet>
#include <QTimer>
#include <QTransform>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QApplication *app, QWidget *parent = nullptr);
    ~Widget();

    void initializeScene();
    void showGameOverDialog(QString message);

private:
    Ui::Widget *m_ui;
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    QSet<int> m_pressedKeys;
    Plane *m_plane;
    quint16 m_points;
    quint8 m_speedY;
    QApplication *m_app;

    bool eventFilter(QObject *object, QEvent *event);
    void changeObjectsYSpeed(bool direction);
    void closeEvent(QCloseEvent *event);

public slots:
    void stopGame(const QString &message);
    void addPoints(quint32 points);
    void playSound(const QUrl &media, int volume);

private slots:
    void advance();
};
#endif // WIDGET_H
