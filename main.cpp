#include "mainmenu.h"
#include "widget.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainMenu w(&a);
    w.show();
    QObject::connect(&w, &MainMenu::quitGame, &a, &QApplication::quit);

    return a.exec();
}
