#include "wall.h"

#include "global.h"
#include "explosion.h"
#include "powerup.h"
#include "level.h"

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


Wall::~Wall() {}


void Wall::update() {}


void Wall::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(16, 0, 16, 16)
    );
}

void Wall::dropPowerUp()
{
    dynamic_cast<Level*>(parent)->createEntity(new PowerUp(pos.x, pos.y, BOMB_NB));
}

void Wall::collisionEvent(Entity * body)
{
    if (dynamic_cast<Explosion*>(body) != nullptr)
    {
        deleteEntity();
        dropPowerUp();
    }
}


QRect Wall::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
