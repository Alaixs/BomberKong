#include "wall.h"

#include "explosion.h"
#include "global.h"
extern const int cellSize;

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
        QRect(pos.x, pos.y, cellSize, cellSize),
        sprite,
        QRect(16, 0, 16, 16)
    );
}


void Wall::collisionEvent(Entity * body)
{
    if (dynamic_cast<Explosion*>(body) != nullptr)
    {
        deleteEntity();
    }
}


QRect Wall::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
