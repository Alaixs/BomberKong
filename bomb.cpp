#include "bomb.h"


#include "qwidget.h"
#include "widget.h"

#include <iostream>

Bomb::Bomb(int X, int Y) : Entity(X, Y) {}

void Bomb::update()
{
    timer--;
    if (timer == 0)
    {
        detonate();
    }
}

void Bomb::draw(QPainter * aPainter)
{
    QPixmap sprite(":/assets/t_bomb.png");
    aPainter->drawPixmap(
        QRect(itsX, itsY, 64, 64),
        sprite
    );
}


void Bomb::detonate()
{
    dynamic_cast<Widget*>(itsParent)->spawnExplosion(itsX, itsY);
    dynamic_cast<Widget*>(itsParent)->spawnExplosion(itsX+64, itsY);
    dynamic_cast<Widget*>(itsParent)->spawnExplosion(itsX-64, itsY);
    dynamic_cast<Widget*>(itsParent)->spawnExplosion(itsX, itsY+64);
    dynamic_cast<Widget*>(itsParent)->spawnExplosion(itsX, itsY-64);
    deleteEntity();
}
