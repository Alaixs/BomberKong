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
            sprite.load("://assets/sprites/t_walls.png");
            break;
    case BOMB_NB:
            sprite.load("://assets/sprites/t_full_heart.png");
            break;
    case BOMB_RANGE:
            sprite.load("://assets/sprites/t_empty_heart.png");
            break;
    case BOMB_TIME:
            sprite.load("://assets/sprites/t_options.png");
            break;
    case ARMOR:
            sprite.load("://assets/sprites/t_options_selected.png");
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
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(16, 0, 16, 16)
        );
}

void PowerUp::collected()
{
    deleteEntity();
}
