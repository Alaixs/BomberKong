#include "wall.h"


Wall::Wall(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_walls.png");
}


Wall::Wall(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_walls.png");
}


void Wall::update()
{

}


void Wall::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(16, 0, 16, 16)
    );
}


QRect Wall::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
