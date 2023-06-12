#include "flame.h"
#include "global.h"


Flame::Flame(int posX, int posY)
    : Enemy(posX, posY)
{
    isOnBoard = false;
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    timer = 187;
}


Flame::Flame(Coordinate position)
    : Enemy(position)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    timer = 187;
}


Flame::~Flame()
{
    delete animation;
}


void Flame::update()
{
    if (isOnBoard)
    {
        if (isOnBoard == 1)
        {
            isOnBoard = 2;
        }
        animation->update();
        timer++;
        srand(time(NULL));
        direction = rand() % 4;
        switch (direction) {
        case 0:
            pos.y += 3;
            break;

        case 1:
            pos.y -= 3;
            break;

        case 2:
            pos.x += 3;
            break;

        case 3:
            pos.x -= 3;
            break;
        }
    }
    else
    {
        pos.y += 3;

        // Delete the barrel once it leaves the screen
        if (rand() % 10 == 0)
        {
            isOnBoard = 1;
        }
        else if (pos.y > 832)
        {
            deleteEntity();
        }
    }
}

void Flame::collisionEvent(Entity *body)
{
    if(dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
    {
        if (isOnBoard == 1)
        {
            isOnBoard = 0;
        }
        switch (direction) {
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
}


void Flame::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
        );
}


QRect Flame::getRect()
{
    return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}
