#include "hammer.h"
#include "global.h"

Hammer::Hammer(int posX, int posY) : Entity(posX,posY)
{
    animation = new AnimationManager;
    sprite.load("://assets/sprites/t_hammer_ground.png");
    animation->play(0,5);
}

Hammer::Hammer(Coordinate pos) : Entity(pos)
{
    animation = new AnimationManager;
    sprite.load("://assets/sprites/t_hammer_ground.png");
    animation->play(0,5);
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
