#include "explosion.h"

#include <QSoundEffect>
#include "global.h"


Explosion::Explosion(int posX, int posY)
    : Entity(posX, posY)
{
    animation = new AnimationManager(2);
    sprite.load("://assets/sprites/t_explosion.png");
    animation->play(0, 6);
    timer = 12;
}


Explosion::Explosion(Coordinate position)
    : Entity(position)
{
    animation = new AnimationManager(2);
    sprite.load("://assets/sprites/t_explosion.png");
    animation->play(0, 6);
    timer = 12;
}


Explosion::~Explosion()
{
    delete animation;
}

void Explosion::update()
{
    animation->update();
    timer--;
    if (timer == 0)
    {
        deleteEntity();
    }
}


void Explosion::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
    );
}


QRect Explosion::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
