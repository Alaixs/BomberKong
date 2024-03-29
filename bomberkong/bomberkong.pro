QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RNG.cpp \
    alternative.cpp \
    animationmanager.cpp \
    banana.cpp \
    barrel.cpp \
    blueflamme.cpp \
    bomb.cpp \
    bombergirl.cpp \
    chocho.cpp \
    bomberland.cpp \
    coordinate.cpp \
    donkeykong.cpp \
    dummy.cpp \
    enemy.cpp \
    explosion.cpp \
    fireball.cpp \
    glagla.cpp \
    hammer.cpp \
    jungle.cpp \
    icebloc.cpp \
    level.cpp \
    guielement.cpp \
    indestructiblewall.cpp \
    input.cpp \
    load.cpp \
    lose.cpp \
    main.cpp \
    mainmenu.cpp \
    monkey.cpp \
    original.cpp \
    playercharacter.cpp \
    powerup.cpp \
    reloaded.cpp \
    save.cpp \
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
    RNG.h \
    alternative.h \
    banana.h \
    blueflamme.h \
    chocho.h \
    bomberland.h \
    dummy.h \
    enemy.h \
    fireball.h \
    glagla.h \
    hammer.h \
    jungle.h \
    icebloc.h \
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
    load.h \
    lose.h \
    mainmenu.h \
    monkey.h \
    original.h \
    playercharacter.h \
    powerup.h \
    reloaded.h \
    save.h \
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

RC_ICONS += assets/icon/logo.ico

