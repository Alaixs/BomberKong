#include "hammer.h"
#include "global.h"

Hammer::Hammer(int posX, int posY) : Entity(posX,posY)
{
    animation = new AnimationManager;
    animation->play(0,5);

    sprite.load("://assets/sprites/t_hammer_ground.png");
}


Hammer::Hammer(Coordinate pos) : Entity(pos)
{
    animation = new AnimationManager;
    animation->play(0,5);

    sprite.load("://assets/sprites/t_hammer_ground.png");
}


Hammer::~Hammer()
{
    delete animation;
}


void Hammer::update()
{
    animation->update();
}


void Hammer::draw(QPainter * painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
        );
}


QRect Hammer::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
