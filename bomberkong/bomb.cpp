#include "bomb.h"

#include "global.h"
#include "input.h"
#include "coordinate.h"
#include "playercharacter.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "game.h"


int cellSize;

Bomb::Bomb(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomb.png");
    animation.play(0, 2);
    timer = 187;
}


Bomb::Bomb(Coordinate position)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_bomb.png");
    animation.play(0, 2);
    timer = 187;
}


Bomb::~Bomb()
{

}


void Bomb::update()
{
    animation.update();
    timer--;
    if (timer == 62)
    {
        animation.play(2, 4);
    }
    if (timer == 0)
    {
        dynamic_cast<Game*>(parent)->createExplosion(pos.x, pos.y);
        dynamic_cast<Game*>(parent)->createExplosion(pos.x + cellSize, pos.y);
        dynamic_cast<Game*>(parent)->createExplosion(pos.x - cellSize, pos.y);
        dynamic_cast<Game*>(parent)->createExplosion(pos.x, pos.y + cellSize);
        dynamic_cast<Game*>(parent)->createExplosion(pos.x, pos.y - cellSize);

        deleteEntity();
        explosionSfx();
    }
}


void Bomb::collisionEvent(Entity * body){
   // Is pushed away when colliding with walls or the player
    if((dynamic_cast<PlayerCharacter*>(body) != nullptr && Input::isActionPressed(PUSH_BOMB)))
    {
        int distX = pos.x - body->getPos().x;
        int distY = pos.y - body->getPos().y;

        if (abs(distX) > abs(distY))
        {
            pos.x += (distX / abs(distX)) * dynamic_cast<PlayerCharacter*>(body)->speed ;
        }
        else
        {
            pos.y += (distY / abs(distY)) * dynamic_cast<PlayerCharacter*>(body)->speed;

        }
    }

    if(dynamic_cast<Wall*>(body) != nullptr )
    {
        int distX = pos.x - body->getPos().x ;
        int distY = pos.y - body->getPos().y;

        if (abs(distX) > abs(distY))
        {
            pos.x += (distX / abs(distX)) * 2;
        }
        else
        {
            pos.y += (distY / abs(distY)) * 2;
        }
    }

    if(dynamic_cast<IndestructibleWall*>(body) != nullptr )
    {
        int distX = pos.x - body->getPos().x ;
        int distY = pos.y - body->getPos().y;

        if (abs(distX) > abs(distY))
        {
            pos.x += (distX / abs(distX)) * 2;
        }
        else
        {
            pos.y += (distY / abs(distY)) * 2;

        }
    }


}


void Bomb::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, cellSize, cellSize),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}

void Bomb::explosionSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_explosion.wav", 0.5);
}



QRect Bomb::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
