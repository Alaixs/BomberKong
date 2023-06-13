#include "banana.h"

#include "coordinate.h"
#include "RNG.h"
#include "playercharacter.h"


Banana::Banana(Coordinate position, Coordinate targetPosition)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_banana.png");
    targetPos = targetPosition;
}


Banana::Banana(int posX, int posY, Coordinate targetPosition)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_banana.png");
    targetPos = targetPosition;
}


void Banana::update()
{
    if (!isOnGround)
    {
        motion = targetPos - pos;

        motion /= motion.length();

        pos += motion * 8;

        if ((targetPos - pos).length() <= 5)
        {
            pos = targetPos;
            isOnGround = true;
        }
    }
}


void Banana::draw(QPainter* painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    if (isOnGround)
    {
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, 32, 32),
            sprite,
            QRect(16, 0, 16, 16)
        );
    }
    else
    {
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, 32, 32),
            sprite,
            QRect(0, 0, 16, 16)
        );
    }

    //painter->setPen(QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap));
    //painter->drawLine(pos.x, pos.y, motion.x, motion.y);
}


QRect Banana::getRect()
{
    return QRect(pos.x + 13, pos.y + 13, 6, 6);
}


void Banana::collisionEvent(Entity* body)
{
    if (dynamic_cast<PlayerCharacter*>(body) != nullptr)
    {
        dynamic_cast<PlayerCharacter*>(body)->stun(187);
        deleteEntity();
    }
}
