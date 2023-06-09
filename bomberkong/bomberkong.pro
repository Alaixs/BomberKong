QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alternative.cpp \
    animationmanager.cpp \
    barrel.cpp \
    bomb.cpp \
    bombergirl.cpp \
    coordinate.cpp \
    donkeykong.cpp \
    dummy.cpp \
    explosion.cpp \
    game.cpp \
    guielement.cpp \
    indestructiblewall.cpp \
    input.cpp \
    loose.cpp \
    main.cpp \
    mainmenu.cpp \
    playercharacter.cpp \
    scene.cpp \
    soundmanager.cpp \
    tutorial.cpp \
    widget.cpp \
    entity.cpp \
    wall.cpp \
    win.cpp

HEADERS += \
    alternative.h \
    dummy.h \
    game.h \
    global.h \
    animationmanager.h \
    barrel.h \
    bomb.h \
    bombergirl.h \
    donkeykong.h \
    explosion.h \
    guielement.h \
    indestructiblewall.h \
    input.h \
    loose.h \
    mainmenu.h \
    playercharacter.h \
    scene.h \
    soundmanager.h \
    tutorial.h \
    widget.h \
    entity.h \
    coordinate.h \
    wall.h \
    win.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
