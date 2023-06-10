#include "powerup.h"
#include "global.h"

PowerUp::PowerUp(int posX, int posY, PowerUpType type)
    : Entity(posX, posY)
{
    itsType = type;
    loadSprite();
}

PowerUp::PowerUp(Coordinate pos, PowerUpType type)
    : Entity(pos)
{
    itsType = type;
    loadSprite();
}

PowerUp::~PowerUp()
{

}

void PowerUp::loadSprite()
{
    switch(itsType) // Change the sprite based on the Power-Up type
    {
        case SPEED:
                sprite.load("://assets/sprites/t_full_heart.png");
                break;
        case BOMB_NB:
                sprite.load("://assets/sprites/t_full_heart.png");
                break;
        case BOMB_RANGE:
                sprite.load("://assets/sprites/t_full_heart.png");
                break;
        case BOMB_TIME:
                sprite.load("://assets/sprites/t_full_heart.png");
                break;
        case ARMOR:
                sprite.load("://assets/sprites/t_full_heart.png");
                break;
        default:
                break;
    }
}

PowerUpType PowerUp::getItsType()
{
    return itsType;
}

void PowerUp::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y, cellSize, cellSize),
        sprite
        );
}

void PowerUp::collected()
{
    deleteEntity();
}

void PowerUp::update()
{

}

void PowerUp::collisionEvent(Entity* body)
{

}

QRect PowerUp::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
