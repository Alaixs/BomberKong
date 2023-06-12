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
            if(timer <= cellSize)
            {
                pos.x += dist / cellSize;
            }
        }
        else if (dynamic_cast<Level*>(parent)->getItsSceneType() != ORIGINAL)
        {
            if (false)
            {
                dynamic_cast<Level*>(parent)->createEntity(new Barrel(pos.x + 2 * cellSize, pos.y + cellSize, dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().y));
            }
            else
            {
                Coordinate SpawnPos;
                if(dynamic_cast<Level*>(parent)->getItsSceneType() == TUTORIAL)
                {
                    if(rand() % 2 == 0)
                    {
                        SpawnPos.x = rand() % 10 * cellSize;
                        SpawnPos.y = ((rand() % 10) + 13) * cellSize ;
                    }
                    else
                    {
                        SpawnPos.x = ((rand() % 10) + 10) * cellSize;
                        SpawnPos.y = ((rand() % 10) + 3) * cellSize ;
                    }
                }
                else
                {
                    SpawnPos.x = rand() % 20 * cellSize;
                    SpawnPos.y = ((rand() % 60) + 4) * cellSize ;
                }
                dynamic_cast<Level*>(parent)->createEntity(new Flame(SpawnPos));
            }
            pos.x = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
        }
        timer = throwingRate;
        isThrowing = false;

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
