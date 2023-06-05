#include "donkeykong.h"

#include "qwidget.h"
#include "barrel.h"
#include "widget.h"
#include <random>
#include "Global.h"
extern int cellSize;

DonkeyKong::DonkeyKong(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_donkeykong.png");
    animation.play(0, 6);
}


DonkeyKong::DonkeyKong(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_donkeykong.png");
    animation.play(0, 6);
}


void DonkeyKong::update()
{
    animation.update();
    timer--;    
    if(timer < 0){
        int random = rand() % 18;
        pos.x = cellSize + (random * cellSize);
        dynamic_cast<Widget*>(parent)->createEntity(new Barrel(pos.x,pos.y+cellSize));
        timer = 62;
    }
}


void DonkeyKong::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 192, 192),
        sprite,
        QRect(animation.getFrame()* 64,0, 64, 64)

    );
}


QRect DonkeyKong::getRect()
{
    return QRect(pos.x, pos.y, 192, 192);
}
