#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "widget.h"

MainMenu::MainMenu(QApplication *app, QWidget *parent)
    : QWidget(parent)
    , m_app(app)
    , m_ui(new Ui::MainMenu)
{
    m_ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete m_ui;
}

void MainMenu::closeEvent(QCloseEvent *event)
{
    emit quitGame();
}

void MainMenu::on_startGameButton_clicked()
{
    Widget *widget = new Widget(m_app);
    widget->show();
    this->destroy();
}

void MainMenu::on_exitGameButton_clicked()
{
    this->destroy();
    emit quitGame();
}

