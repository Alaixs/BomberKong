#include "bomb.h"


#include <iostream>>

Bomb::Bomb(int X, int Y) : Entity(X, Y)
{
}


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
    deleteEntity();
}
