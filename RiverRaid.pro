QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basegameobject.cpp \
    bridge.cpp \
    bullet.cpp \
    enemyplane.cpp \
    fuel.cpp \
    helicopter.cpp \
    land.cpp \
    main.cpp \
    mainmenu.cpp \
    objectdescription.cpp \
    plane.cpp \
    river.cpp \
    ship.cpp \
    widget.cpp

HEADERS += \
    basegameobject.h \
    bridge.h \
    bullet.h \
    enemyplane.h \
    fuel.h \
    helicopter.h \
    land.h \
    mainmenu.h \
    objectdescription.h \
    objecttype.h \
    plane.h \
    river.h \
    ship.h \
    widget.h

FORMS += \
    mainmenu.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
