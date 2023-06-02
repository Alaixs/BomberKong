#include "donkeykong.h"
#include "playercharacter.h"
#include "qwidget.h"
#include "tonneaux.h"
#include "widget.h"

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
        pos.x+=48;
        dynamic_cast<Widget*>(parent)->createEntity(new Tonneaux(pos));
        timer=0;
    }
    timer++;
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
