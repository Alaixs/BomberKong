#include "tonneaux.h"

#include "widget.h"


Tonneaux::Tonneaux(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomb.png");
    animation.play(0, 2);
}

Tonneaux::Tonneaux(Coordinate position)
    : Entity(position)
{
    sprite.load("://assets/sprites/t_bomb.png");
    animation.play(0, 2);
}


void Tonneaux::update()
{
    animation.update();
    timer++;
    pos.y+=3;

    if (timer%50==0)
    {
        animation.play(2, 4);
    }
    else if (timer%50==0)
    {
        animation.play(4, 2);
    }
    {
        animation.play(2, 4);
    }
    if (timer==400)
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
