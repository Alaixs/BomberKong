#include "flame.h"

#include "global.h"
#include "RNG.h"


Flame::Flame(int posX, int posY)
    : Enemy(posX, posY)
{
    spawnCoordinate = Coordinate(posX, posY);
    isOnBoard = 1;
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    direction = RNG::randomInt(0, 3);
    timer = 187;
    yDirection = posY;
}


Flame::Flame(Coordinate position, int DKY)
    : Enemy(position.x, DKY)
{
    spawnCoordinate = position;
    isOnBoard = 1;
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    direction = RNG::randomInt(0, 3);
    timer = 187;
    yDirection = position.y;
}


Flame::~Flame()
{
    delete animation;
}


void Flame::update()
{
    animation->update();
    timer--;
    if(isOnBoard == 0)
    {
        if(timer <= 0)
        {
            timer = 187;
            direction = RNG::randomInt(0, 3);
        }

        if(timer < 32)
        {
            if(direction == 0)
            {
                pos.y-= 1;
            }
            else if (direction == 1)
            {
                pos.y += 1;
            }
            else if (direction == 2)
            {
                pos.x -= 1;
            }
            else
            {
                pos.x += 1;
            }

        }
    }
    else
    {
        pos.y += 1;
        if(pos.y == yDirection )
        {
            isOnBoard = 0;
        }
    }

}

void Flame::collisionEvent(Entity *body)
{


    if ((dynamic_cast<Wall*>(body) != nullptr
         || dynamic_cast<IndestructibleWall*>(body) != nullptr)
        && isOnBoard == 00)
    {
        if(direction == 0)
        {
            pos.y += 3;
        }
        else if (direction == 1)
        {
            pos.y -= 3;
        }
        else if (direction == 2)
        {
            pos.x += 3;
        }
        else if (direction == 3)
        {
            pos.x -= 3;
        }
    }

    if (dynamic_cast<Explosion*>(body) != nullptr || (dynamic_cast<PlayerCharacter*>(body) != nullptr && dynamic_cast<PlayerCharacter*>(body)->isOnHammerEffect()))
    {
        deleteEntity();
    }
}


void Flame::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    if (flipped)
    {
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1,1)),
            QRect(animation->getFrame() * 16, 0, 16, 16)
            );
    }
    else
    {
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite,
            QRect(animation->getFrame() * 16, 0, 16, 16)
            );
    }

}


QRect Flame::getRect()
{
    return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}
