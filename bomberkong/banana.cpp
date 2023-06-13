#include "banana.h"

#include "coordinate.h"


Banana::Banana(Coordinate position, Coordinate targetPos)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_banana.png");
}


Banana::Banana(int posX, int posY, Coordinate targetPos)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_banana.png");
}


void Banana::update()
{
    motion = pos - targetPos;
    motion /= motion.length();
    pos += motion;
}


void Banana::draw(QPainter* painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, 32, 32),
        sprite,
        QRect(0, 0, 16, 16)
    );
}
