#include "wall.h"

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
    aPainter->fillRect(
        QRect(itsX, itsY, 30, 30),
        QBrush(QColor(70, 78, 79))
    );
}


QRect Wall::getRect()
{
    return QRect(itsX, itsY, 30, 30);
}
