#include "indestructiblewall.h"

#include "global.h"


IndestructibleWall::IndestructibleWall(int posX, int posY, SceneType Lvl)
    : Entity(posX, posY)
{
    if( Lvl == TUTORIAL ||
        Lvl == ORIGINAL ||
        Lvl == RELOADED ||
        Lvl == BOMBERLAND ||
        Lvl == JUNGLEDK)
    {
        sprite.load("://assets/sprites/t_walls.png");
    }
    else if (Lvl == CHOCHO)
    {
        sprite.load("://assets/sprites/t_bloc_chocho.png");
    }
    else if (Lvl == GLAGLA)
    {
        sprite.load("://assets/sprites/t_bloc_glagla.png");
    }
}


IndestructibleWall::IndestructibleWall(Coordinate pos, SceneType Lvl)
    : Entity(pos)
{
    if( Lvl == TUTORIAL ||
        Lvl == ORIGINAL ||
        Lvl == RELOADED ||
        Lvl == BOMBERLAND ||
        Lvl == JUNGLEDK)
    {
        sprite.load("://assets/sprites/t_walls.png");
    }
    else if (Lvl == CHOCHO)
    {
        sprite.load("://assets/sprites/t_bloc_chocho.png");
    }
    else if (Lvl == GLAGLA)
    {
        sprite.load("://assets/sprites/t_bloc_glagla.png");
    }
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
