#include "bombergirl.h"
#include "playercharacter.h"


BomberGirl::BomberGirl(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomb.png");
}


BomberGirl::BomberGirl(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bomb.png");
}


void BomberGirl::update()
{

}


void BomberGirl::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(48, 0, 16, 16)
    );
}


void BomberGirl::collisionEvent(Entity * body)
{
    if (dynamic_cast<PlayerCharacter*>(body) != nullptr)
    {
        deleteEntity();
    }
}


QRect BomberGirl::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
