#include "explosion.h"
#include <QDebug>


Explosion::Explosion(int posX, int posY)
    : Entity(posX, posY)
{
    qDebug() << "construct principale" ;
    sprite.load("://assets/sprites/t_explosion.png");
    animation.setInterval(2);
    animation.play(0, 6);
}


Explosion::Explosion(Coordinate position)
    : Entity(position)
{
        qDebug() << "construct coordinate" ;
    sprite.load("://assets/sprites/t_explosion.png");
    animation.setInterval(2);
    animation.play(0, 6);
}


void Explosion::update()
{
            qDebug() << "Update" ;
    animation.update();
    timer--;
    if (timer == 0)
    {
        deleteEntity();
    }
}


void Explosion::draw(QPainter * painter)
{
   qDebug() << "draw painter" ;
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect Explosion::getRect()
{
            qDebug() << "getrect baby" ;
    return QRect(pos.x, pos.y, 48, 48);
}
