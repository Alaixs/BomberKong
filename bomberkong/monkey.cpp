#include "monkey.h"

#include "RNG.h"
#include "global.h"
#include "level.h"


Monkey::Monkey(Coordinate dropPosition, QString spriteSource)
    : Entity(dropPosition)
{

    sprite.load(spriteSource);

    animation = new AnimationManager();
    targetPosition = pos;
}


Monkey::~Monkey()
{
    delete animation;
}


void Monkey::update()
{
    if ((targetPosition - pos).length() <= 2)
    {
        Coordinate nextTile(targetPosition);
        do
        {
            int dir = RNG::randomInt(0, 3);
            switch (dir)
            {
            case 0:
                nextTile = targetPosition + Coordinate(0, -32);
                break;
            case 1:
                nextTile = targetPosition + Coordinate(32, 0);
                break;
            case 2:
                nextTile = targetPosition + Coordinate(0, 32);
                break;
            case 3:
                nextTile = targetPosition + Coordinate(-32, 0);
                break;
            }
        } while (dynamic_cast<Level*>(parent)->isPointInWall(nextTile));
        targetPosition = nextTile;
    }

    motion = targetPosition - pos;
    motion /= motion.length();

    pos += motion * 2;
}


void Monkey::draw(QPainter* painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
    );
}


QRect Monkey::getRect()
{
    return QRect(pos.x, pos.y, 16, 16);
}
