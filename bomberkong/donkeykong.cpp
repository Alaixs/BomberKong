#include "donkeykong.h"

#include <random>
#include "global.h"
#include "game.h"
#include "barrel.h"


DonkeyKong::DonkeyKong(int posX, int posY)
    : Entity(posX, posY)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_donkeykong.png");
    animation->play(0, 6);
    throwingRate = 100;
    timer = throwingRate;
    isThrowing = false;
}


DonkeyKong::DonkeyKong(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_donkeykong.png");
    animation->play(0, 6);
    throwingRate = 100;
    timer = throwingRate;
    isThrowing = false;
}


DonkeyKong::~DonkeyKong()
{
    delete animation;
}


void DonkeyKong::update()
{
    animation->update();
    timer--;
    if(timer <= 0){
        dynamic_cast<Game*>(parent)->createEntity(new Barrel(pos.x + 2 * cellSize, pos.y + cellSize));
        int random = rand() % 18;
        newPos = random * cellSize + cellSize;
        dist = newPos - pos.x;
        timer = throwingRate;
        isThrowing = false;
    }

    if(timer <= cellSize)
    {
        pos.x += dist / cellSize;
    }

    if(timer == 10)
    {
        isThrowing = true;
    }

    if(isThrowing)
    {
        animation->play(6,9);
    }
    else
    {
        animation->play(0,6);
    }
}


void DonkeyKong::draw(QPainter* painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 4 * cellSize, 4 * cellSize),
        sprite,
        QRect(animation->getFrame() * 64, 0, 64, 64)
    );
}


QRect DonkeyKong::getRect()
{
    return QRect(pos.x, pos.y, 4 * cellSize, 4 * cellSize);
}
