#include "mainmenu.h"
#include "widget.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/fonts/visitor1.ttf");

    MainMenu menu(&app);
    menu.show();
    QObject::connect(&menu, &MainMenu::quitGame, &app, &QApplication::quit);

    return app.exec();
}
