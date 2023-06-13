#include "fireball.h"
#include "global.h"

FireBall::FireBall(int posX, int posY, int endYPos)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_dk_fireball.png");

    animation = new AnimationManager;
    animation->play(0,6);

    timer = 800;

    endY = endYPos;
    isFlying = true;
}

FireBall::FireBall(Coordinate pos, int endYPos)
    : Entity(pos.x, pos.y)
{
    sprite.load("://assets/sprites/t_dk_fireball.png");

    animation = new AnimationManager;

    timer = 800;

    endY = endYPos;
    isFlying = true;
}

FireBall::~FireBall()
{
    delete animation;
}

void FireBall::update()
{
    animation->update();
    if(isFlying == true)
    {
        pos.y += 1;
        if(pos.y == endY)
        {
            isFlying = false;
        }
    }
    else
    {
        timer--;
        if(timer == 0)
        {
            deleteEntity();
        }
    }
}


void FireBall::draw(QPainter * painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
        );
}

bool FireBall::getIsFlying()
{
    return isFlying;
}

QRect FireBall::getRect()
{
    return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}
