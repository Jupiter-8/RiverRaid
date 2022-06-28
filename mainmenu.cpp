#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "widget.h"

MainMenu::MainMenu(QApplication *app, QWidget *parent)
    : app(app)
    , QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()
{
    Widget *w = new Widget(app);
    w->show();
    this->destroy();
}

void MainMenu::on_pushButton_2_clicked()
{
    this->destroy();
    emit quitGame();
}

void MainMenu::closeEvent(QCloseEvent *event)
{
    emit quitGame();
}
