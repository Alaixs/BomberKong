#include "wall.h"

#include "global.h"
#include "explosion.h"
#include "powerup.h"
#include "level.h"

Wall::Wall(int posX, int posY)
    : Entity(posX, posY)
{

}


Wall::Wall(Coordinate pos)
    : Entity(pos)
{

}

void Wall::setSprite()
{
    qDebug("Wall");
    if( dynamic_cast<Level*>(parent)->getItsSceneType() == TUTORIAL ||
        dynamic_cast<Level*>(parent)->getItsSceneType() == ORIGINAL ||
        dynamic_cast<Level*>(parent)->getItsSceneType() == RELOADED ||
        dynamic_cast<Level*>(parent)->getItsSceneType() == BOMBERLAND ||
        dynamic_cast<Level*>(parent)->getItsSceneType() == JUNGLEDK)
    {
        sprite.load("://assets/sprites/t_walls.png");
    }
    else if (dynamic_cast<Level*>(parent)->getItsSceneType() == CHOCHO)
    {
        sprite.load("://assets/sprites/t_bloc_chocho.png");
    }
    else if (dynamic_cast<Level*>(parent)->getItsSceneType() == GLAGLA)
    {
        sprite.load("://assets/sprites/t_bloc_glagla.png");
    }
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
    std::srand(std::time(0));
    int randomNumber = std::rand() % 5; // Selects a random power up

    switch (randomNumber)
    {
    case 0:
        dynamic_cast<Level*>(parent)->createEntity(new PowerUp(pos.x, pos.y, SPEED));
        break;

    case 1:
        dynamic_cast<Level*>(parent)->createEntity(new PowerUp(pos.x, pos.y, BOMB_NB));
        break;

    case 2:
        dynamic_cast<Level*>(parent)->createEntity(new PowerUp(pos.x, pos.y, BOMB_RANGE));
        break;

    case 3:
        dynamic_cast<Level*>(parent)->createEntity(new PowerUp(pos.x, pos.y, BOMB_TIME));
        break;

    case 4:
        dynamic_cast<Level*>(parent)->createEntity(new PowerUp(pos.x, pos.y, ARMOR));
        break;

    default:
        break;
    }
}


void Wall::collisionEvent(Entity * body)
{
    if (dynamic_cast<Explosion*>(body) != nullptr)
    {
        // Destroy if colliding with an explosion
        deleteEntity();

        if (dynamic_cast<Level*>(parent)->getItsSceneType() != ORIGINAL) // The Power-Up can't appear in the Original level
        {
            // Drops a power up with a 25% chance
            std::srand(std::time(0));
            int randomNumber = std::rand() % 100;

            if (randomNumber <= 25) {
                dropPowerUp();
            }
        }
    }

}


QRect Wall::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
