#include "explosion.h"
#include <QSoundEffect>


Explosion::Explosion(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_explosion.png");
    animation.setInterval(2);
    animation.play(0, 6);
}


Explosion::Explosion(Coordinate position)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_explosion.png");
    animation.setInterval(2);
    animation.play(0, 6);
}


void Explosion::update()
{
    animation.update();
    timer--;
    if (timer == 0)
    {
        deleteEntity();
    }
}


void Explosion::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect Explosion::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
