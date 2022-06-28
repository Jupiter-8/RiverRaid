#ifndef MAINMENU_H
#define MAINMENU_H

#include <QApplication>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QApplication *app, QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void quitGame();

private:
    Ui::MainMenu *ui;
    QApplication *app;

    void closeEvent(QCloseEvent *event);
};

#endif // MAINMENU_H
