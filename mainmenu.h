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

private:
    QApplication *m_app;
    Ui::MainMenu *m_ui;

    void closeEvent(QCloseEvent *event);

private slots:
    void on_startGameButton_clicked();
    void on_exitGameButton_clicked();

signals:
    void quitGame();
};

#endif // MAINMENU_H
