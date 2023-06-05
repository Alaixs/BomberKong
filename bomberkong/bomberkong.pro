QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animationmanager.cpp \
    barrel.cpp \
    bomb.cpp \
    bombergirl.cpp \
    coordinate.cpp \
    demicharacter.cpp \
    donkeykong.cpp \
    explosion.cpp \
    indestructiblewall.cpp \
    input.cpp \
    main.cpp \
    playercharacter.cpp \
    soundmanager.cpp \
    widget.cpp \
    entity.cpp \
    wall.cpp \

HEADERS += \
    demicharacter.h \
    global.h \
    animationmanager.h \
    barrel.h \
    bomb.h \
    bombergirl.h \
    donkeykong.h \
    explosion.h \
    indestructiblewall.h \
    input.h \
    playercharacter.h \
    soundmanager.h \
    widget.h \
    entity.h \
    coordinate.h \
    wall.h \

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
