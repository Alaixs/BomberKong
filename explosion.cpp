#include "explosion.h"
#include <QSoundEffect>
#include <QDebug>

Explosion::Explosion(int X, int Y) : Entity(X, Y) {}

void Explosion::update()
{
    timer--;
    if (timer == 0)
    {
        deleteEntity();
    }

}

void Explosion::draw(QPainter * aPainter)
{
    QPixmap sprite(":/assets/t_explosion.png");
    aPainter->drawPixmap(
        QRect(itsX, itsY, 64, 64),
        sprite
        );
}

QRect Explosion::getRect()
{
    return QRect(itsX, itsY, 64, 64);
}
