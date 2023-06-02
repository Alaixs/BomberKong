#include "indestructiblewall.h"
#include "explosion.h"


IndestructibleWall::IndestructibleWall(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_walls.png");
}


IndestructibleWall::IndestructibleWall(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_walls.png");
}


void IndestructibleWall::update()
{

}


void IndestructibleWall::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(16, 0, 16, 16)
    );
}

QRect IndestructibleWall::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
