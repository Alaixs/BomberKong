#include "donkeykong.h"

#include "qwidget.h"
#include "barrel.h"
#include "widget.h"
#include <random>
#include "global.h"
extern const int cellSize;

DonkeyKong::DonkeyKong(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_donkeykong.png");
    animation.play(0, 6);
    timer = 0;
}


DonkeyKong::DonkeyKong(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_donkeykong.png");
    animation.play(0, 6);
    timer = 0;
}


void DonkeyKong::update()
{

    animation.update();
    timer--;

    if(timer < 0){
        dynamic_cast<Widget*>(parent)->createEntity(new Barrel(pos.x,pos.y+cellSize));
        int random = rand() % 18;
        newPos = random * cellSize + cellSize;
        dist = newPos - pos.x;
        timer = 100;
    }

    if(pos.x != newPos)
    {
        pos.x += dist/100;
    }
}


void DonkeyKong::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 4 * cellSize, 4 * cellSize),
        sprite,
        QRect(animation.getFrame()* 64,0, 64, 64)

    );
}


QRect DonkeyKong::getRect()
{
    return QRect(pos.x, pos.y, 4 * cellSize, 4 * cellSize);
}
