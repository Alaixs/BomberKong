#include "wall.h"
#include "qwidget.h"

Wall::Wall(int X, int Y)
    : Entity(X, Y)
{
    itsX = X;
    itsY = Y;
}


void Wall::update()
{}

void Wall::draw(QPainter * aPainter)
{
    QPixmap sprite(":/assets/t_wall.png");
    aPainter->drawPixmap(
        QRect(itsX, itsY, 64, 64),
        sprite
    );
}


QRect Wall::getRect()
{
    return QRect(itsX, itsY, 64, 64);
}
