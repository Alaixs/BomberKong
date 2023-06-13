#include "monkey.h"

#include "RNG.h"
#include "global.h"
#include "level.h"


Monkey::Monkey(Coordinate dropPosition, QString spriteSource)
    : Entity(dropPosition.x, -1280)
{

    sprite.load(spriteSource);
    lianaSprite.load("://assets/sprites/t_liana.png");

    animation = new AnimationManager();
    animation->play(4, 8);

    targetPosition = dropPosition;

    isOnGround = false;

    timer = 625;
}


Monkey::~Monkey()
{
    delete animation;
}


void Monkey::update()
{
    if (isOnGround)
    {
        timer--;
    }

    if (timer == 0)
    {
        deleteEntity();
    }

    animation->update();

    if ((targetPosition - pos).length() <= 2)
    {
        isOnGround = true;

        // Select a target
        Coordinate nextTile(targetPosition);
        do
        {
            // Select a tile right next to current position
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

    // Move to target
    motion = targetPosition - pos;
    motion /= motion.length();

    pos += motion * 2;
}


void Monkey::draw(QPainter* painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();

    if (!isOnGround)
    {
        // Draws the liana
        int lianaLength = abs(targetPosition.y - (-1280)) / 32;

        // Draws a liana section for each cell between the target and the spawn point
        for (int i = 0; i < lianaLength; i++)
        {
            painter->drawPixmap(
                QRect(pos.x, (-1280) + (i * 32) - offset.y + 416, cellSize, cellSize),
                lianaSprite,
                QRect(0, 0, 16, 16)
                );
        }
        // Draws the tip of the liana
        painter->drawPixmap(
            QRect(pos.x, targetPosition.y - offset.y + 416, cellSize, cellSize),
            lianaSprite,
            QRect(0, 16, 16, 16)
            );
    }

    if (motion.x <= 0)
    {
        // Draws the normal sprite
        Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite,
            QRect(animation->getFrame() * 16, 0, 16, 16)
        );
    }
    else
    {
        // Draws the flipped sprite
        Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((8 - animation->getFrame()) * 16, 0, 16, 16)
        );
    }
}


QRect Monkey::getRect()
{
    if (isOnGround)
    {
        return QRect(pos.x + 5, pos.y + 5, 22, 22);
    }
    else
    {
        return QRect(0, 0, 0, 0);
    }
}
