#include "mainmenu.h"
#include "widget.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainMenu menu(&app);
    menu.show();
    QObject::connect(&menu, &MainMenu::quitGame, &app, &QApplication::quit);

    return app.exec();
}
