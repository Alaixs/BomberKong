#include "donkeykong.h"

#include <random>
#include "global.h"
#include "level.h"
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
        if (dynamic_cast<Level*>(parent)->getItsSceneType() == ORIGINAL)
        {
            dynamic_cast<Level*>(parent)->createEntity(new Barrel(pos.x + 2 * cellSize, pos.y + cellSize));
            int random = rand() % 18;
            newPos = random * cellSize - cellSize;
            dist = newPos - pos.x;
        }
        else if (dynamic_cast<Level*>(parent)->getItsSceneType() == RELOADED)
        {
            if (rand()%8)
            {
                dynamic_cast<Level*>(parent)->createEntity(new Barrel(pos.x + 2 * cellSize, pos.y + cellSize));
            }
            else
            {
                dynamic_cast<Level*>(parent)->createEntity(new Flame(pos.x + 2 * cellSize, pos.y + cellSize));
            }
            int random = rand() % 18;
            newPos = random * cellSize - cellSize;
            dist = newPos - pos.x;
        }
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
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize * 4, cellSize * 4),
        sprite,
        QRect(animation->getFrame() * 64, 0, 64, 64)
    );
}


QRect DonkeyKong::getRect()
{
    return QRect(pos.x, pos.y, 4 * cellSize, 4 * cellSize);
}
