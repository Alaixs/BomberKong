#include "barrel.h"

#include "global.h"


Barrel::Barrel(int posX, int posY, int endYPos)
    : Entity(posX, posY)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_barrel.png");
    shadow.load("://assets/sprites/t_ombre.png");
    animation->play(0, 3);
    timer = 187;
    endY = endYPos;
    isFlying = true;
}


Barrel::Barrel(Coordinate position, int endYPos)
    : Entity(position)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_barrel.png");
    shadow.load("://assets/sprites/t_ombre.png");
    animation->play(0, 3);
    timer = 187;
    endY = endYPos;
    isFlying = true;
}


Barrel::~Barrel()
{
    delete animation;
}


void Barrel::update()
{
    animation->update();
    timer++;
    pos.y += 3;

    // Delete the barrel once it leaves the screen
    if (dynamic_cast<Level*>(parent)->getItsSceneType() == ORIGINAL)
    {
        if (pos.y > endY)
        {
            deleteEntity();
        }
    }
    else if (dynamic_cast<Level*>(parent)->getItsSceneType() != ORIGINAL)
    {
        if (pos.y > endY)
        {
            isFlying = false;
        }
        if (!isFlying)
        {
            deleteEntity();
        }
    }
}


void Barrel::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
    );
    if (dynamic_cast<Level*>(parent)->getItsSceneType() != ORIGINAL)
    {
        painter->drawPixmap(
            QRect(pos.x, endY - offset.y + 416, cellSize, cellSize),
            shadow,
<<<<<<< HEAD
            QRect(0, 0, 16, 16)
=======
            QRect(0,0, 16, 16)
>>>>>>> 50f216d1c358c096658ea2a133a854eb406ffbe6
            );
    }
}


QRect Barrel::getRect()
{
    return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}

bool Barrel::getIsFlying()
{
    return isFlying;
}
