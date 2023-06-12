#include "flame.h"
#include "global.h"


Flame::Flame(int posX, int posY)
    : Enemy(posX, posY)
{
    srand(time(NULL) % rand());
    spawnCoordinate = Coordinate(posX, posY);
    isOnBoard = 0;
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
    isOnBoard = 0;
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
    timer++;
    direction = (rand() + direction) % 4;
    if (pos.y < 10 * cellSize - spawnCoordinate.y)
    {
        pos.y += 3;
    }

    if (isOnBoard > 0)
    {
        if (isOnBoard == 1)
        {
            isOnBoard = 2;
        }
        if (timer > 10)
        {
            switch (direction)
            {
            case 0:
                pos.y += 3;
                break;

            case 1:
                pos.y -= 3;
                break;

            case 2:
                pos.x += 3;
                flipped = true;
                break;

            case 3:
                pos.x -= 3;
                flipped = false;
                break;
            }
            timer = 0;
        }
    }
    else
    {
        pos.y += 3;

        if(!(rand() % 9))
        {
            isOnBoard = 1;
        }
        if (pos.y > 832)
        {
            deleteEntity();
        }
    }
}

void Flame::collisionEvent(Entity *body)
{
    if(isOnBoard < 2)
    {
        if (dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
        {
            isOnBoard = 0;
        }
    }
    else if(dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
    {
        switch (direction)
        {
        case 0:
            pos.y -= 3;
            break;

        case 1:
            pos.y += 3;
            break;

        case 2:
            pos.x -= 3;
            break;

        case 3:
            pos.x += 3;
            break;
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
