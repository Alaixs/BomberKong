#include "barrel.h"

#include "global.h"


Barrel::Barrel(int posX, int posY, int endYPos)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_barrel.png");
    shadow.load("://assets/sprites/t_ombre.png");

    animation = new AnimationManager();
    animation->play(0, 3);

    timer = 187;

    endY = endYPos; // The position at which the barrel is destroyed (once not visible)

    isFlying = true;
}


Barrel::Barrel(Coordinate position, int endYPos)
    : Entity(position)
{
    shadow.load("://assets/sprites/t_ombre.png");
    sprite.load("://assets/sprites/t_barrel.png");

    animation = new AnimationManager();    

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
    // Offsets the sprite according to the player character's position (vertical scrolling)
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
            QRect(0, 0, 16, 16)
<<<<<<< HEAD
            );
=======
        );
>>>>>>> 60474ac3eb47a4c84e6c4d202945a26a6b7fd2ff
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
