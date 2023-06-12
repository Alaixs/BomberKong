#include "indestructiblewall.h"

#include "global.h"


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


IndestructibleWall::~IndestructibleWall()
{

}


void IndestructibleWall::update()
{

}


void IndestructibleWall::draw(QPainter * painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(0, 0, 16, 16)
    );
}


QRect IndestructibleWall::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
