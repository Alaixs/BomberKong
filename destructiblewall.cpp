#include "destructiblewall.h"
#include "qwidget.h"

DestructibleWall::DestructibleWall(int X, int Y) : Entity(X, Y){}


void DestructibleWall::update(){}


void DestructibleWall::draw(QPainter * aPainter)
{
    QPixmap sprite(":/assets/t_destructible_wall.png");
    aPainter->drawPixmap(
        QRect(itsX, itsY, 64, 64),
        sprite
    );
}


QRect DestructibleWall::getRect()
{
    return QRect(itsX, itsY, 64, 64);
}
