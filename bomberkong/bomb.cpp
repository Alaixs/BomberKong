#include "bomb.h"

#include "input.h"
#include "widget.h"
#include "playercharacter.h"
#include "coordinate.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "Global.h"

Bomb::Bomb(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomb.png");
    animation.play(0, 2);
}


Bomb::Bomb(Coordinate position)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_bomb.png");
    animation.play(0, 2);
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
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x, pos.y);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x + cellSize, pos.y);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x - cellSize, pos.y);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x, pos.y + cellSize);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x, pos.y - cellSize);

        deleteEntity();
        explosionSfx();
    }
}


void Bomb::collisionEvent(Entity * body){
    // Is pushed away when colliding with walls or the player
    if((dynamic_cast<PlayerCharacter*>(body) != nullptr && Input::isActionPressed(PUSH_BOMB))
        || dynamic_cast<Wall*>(body) != nullptr
        || dynamic_cast<IndestructibleWall*>(body) != nullptr)
    {
        if(body->getPos().x > pos.x){
            pos.x -= cellSize;
        }
        else if(body->getPos().x < pos.x){
            pos.x += cellSize;
        }
        else if(body->getPos().y > pos.y){
            pos.y -= cellSize;
        }
        else{
            pos.y += cellSize;
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
