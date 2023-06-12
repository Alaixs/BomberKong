#include "flame.h"
#include "global.h"


Flame::Flame(int posX, int posY)
    : Enemy(posX, posY)
{
    srand(time(NULL) % rand());
    spawnCoordinate = Coordinate(posX, posY);
    isOnBoard = 1;
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    direction = rand() % 4;
    timer = 187;
}


Flame::Flame(Coordinate position)
    : Enemy(position)
{
    srand(time(NULL) % rand());
    spawnCoordinate = position;
    isOnBoard = 1;
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    direction = rand() % 4;
    timer = 187;
}


Flame::~Flame()
{
    delete animation;
}


void Flame::update()
{
    animation->update();
    timer--;

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

    if(timer == 0)
    {
        timer = 187;
        direction = (rand() + direction) % 4;
    }

}

void Flame::collisionEvent(Entity *body)
{


    if (dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
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
