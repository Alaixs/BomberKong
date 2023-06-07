#include "bombergirl.h"

#include <QTimer>
#include "global.h"


//extern const int cellSize;

BomberGirl::BomberGirl(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bombergirl.png");
    animation.play(0, 11);
}


BomberGirl::BomberGirl(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bombergirl.png");
    animation.play(0, 11);
}


void BomberGirl::update()
{
    animation.update();
}


void BomberGirl::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, cellSize, cellSize),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect BomberGirl::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
