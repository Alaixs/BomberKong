#include "bomb.h"

#include "input.h"
#include "widget.h"
#include "playercharacter.h"
#include "coordinate.h"
#include "wall.h"
#include "indestructiblewall.h"

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
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x + 48, pos.y);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x - 48, pos.y);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x, pos.y + 48);
        dynamic_cast<Widget*>(parent)->createExplosion(pos.x, pos.y - 48);

        deleteEntity();
    }
}

void Bomb::collisionEvent(Entity * body){
    if((dynamic_cast<PlayerCharacter*>(body) != nullptr && Input::isActionPressed(PUSH_BOMB))
           || (dynamic_cast<Wall*>(body) != nullptr
            || dynamic_cast<IndestructibleWall*>(body) != nullptr)){
        if(body->getPos().x>pos.x){
            pos.x-=48;
        }
        else if(body->getPos().x<pos.x){
            pos.x+=48;
        }
        else if(body->getPos().y>pos.y){
            pos.y-=48;
        }
        else{
            pos.y+=48;
        }
    }
}

void Bomb::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect Bomb::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
