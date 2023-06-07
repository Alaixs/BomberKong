#include "barrel.h"
#include "global.h"

//int cellSize;

Barrel::Barrel(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_barrel.png");
    animation.play(0, 3);
    timer = 187;
}


Barrel::Barrel(Coordinate position)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_barrel.png");
    animation.play(0, 3);
    timer = 187;
}


void Barrel::update()
{
    animation.update();
    timer++;
    pos.y += 3;

    if (timer == 1000)
    {
        deleteEntity();
    }
}


void Barrel::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, cellSize, cellSize),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect Barrel::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}