#include "tonneaux.h"


Tonneaux::Tonneaux(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_barrel.png");
    animation.play(0, 3);
}

Tonneaux::Tonneaux(Coordinate position)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_barrel.png");
    animation.play(0, 3);
}


void Tonneaux::update()
{
    animation.update();
    timer++;
    pos.y += 3;

    if (timer == 1000)
    {
        deleteEntity();
    }
}


void Tonneaux::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect Tonneaux::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
