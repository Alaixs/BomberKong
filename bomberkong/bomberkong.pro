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
    chocho.cpp \
    coordinate.cpp \
    donkeykong.cpp \
    dummy.cpp \
    enemy.cpp \
    explosion.cpp \
    glagla.cpp \
    hammer.cpp \
    level.cpp \
    guielement.cpp \
    indestructiblewall.cpp \
    input.cpp \
    lose.cpp \
    main.cpp \
    mainmenu.cpp \
    original.cpp \
    playercharacter.cpp \
    powerup.cpp \
    reloaded.cpp \
    scene.cpp \
    settingsmenu.cpp \
    soundmanager.cpp \
    textlabel.cpp \
    tutorial.cpp \
    widget.cpp \
    entity.cpp \
    wall.cpp \
    win.cpp \
    flame.cpp

HEADERS += \
    alternative.h \
    chocho.h \
    dummy.h \
    enemy.h \
    glagla.h \
    hammer.h \
    level.h \
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
    lose.h \
    mainmenu.h \
    original.h \
    playercharacter.h \
    powerup.h \
    reloaded.h \
    scene.h \
    settingsmenu.h \
    soundmanager.h \
    textlabel.h \
    tutorial.h \
    widget.h \
    entity.h \
    coordinate.h \
    wall.h \
    win.h \
    flame.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
