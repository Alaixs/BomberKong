#include "donkeykong.h"

#include "qwidget.h"
#include "barrel.h"
#include "widget.h"
#include <random>


DonkeyKong::DonkeyKong(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomb.png");
}


DonkeyKong::DonkeyKong(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bomb.png");
}


void DonkeyKong::update()
{
    if(timer > 62){
        int random = rand() % 18;
        pos.x = 48 + (random * 48);
        dynamic_cast<Widget*>(parent)->createEntity(new Barrel(pos));
        timer = 0;
    }
    timer++;
    if(timer % 50 == 0){
        animation.play(2, 4);
    }
    else if(timer % 50 == 25){
        animation.play(4, 2);
    }
}


void DonkeyKong::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(48, 0, 16, 16)
    );
}


QRect DonkeyKong::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
