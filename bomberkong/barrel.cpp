#include "barrel.h"

#include "global.h"


Barrel::Barrel(int posX, int posY, int endYPos)
    : Entity(posX, posY)
{
    animation = new AnimationManager();
    animation->play(0, 3);

    sprite.load("://assets/sprites/t_barrel.png");

    timer = 187;

    endY = endYPos; // The position at which the barrel is destroyed (once not visible)
}


Barrel::Barrel(Coordinate position, int endYPos)
    : Entity(position)
{
    animation = new AnimationManager();
    animation->play(0, 3);

    sprite.load("://assets/sprites/t_barrel.png");

    timer = 187;

    endY = endYPos; // The position at which the barrel is destroyed (once not visible)
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
    if (pos.y > endY)
    {
        deleteEntity();
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
}


QRect Barrel::getRect()
{
    return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}
