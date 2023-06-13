#include "donkeykong.h"

#include <random>
#include "blueflamme.h"
#include "fireball.h"
#include "global.h"
#include "icebloc.h"
#include "level.h"
#include "barrel.h"
#include "banana.h"
#include "RNG.h"
#include "monkey.h"


DonkeyKong::DonkeyKong(int posX, int posY, SceneType Lvl)
    : Entity(posX, posY)
{
    if(Lvl == CHOCHO)
    {
        sprite.load("://assets/sprites/t_donkeykong_fire.png");
    }
    else if(Lvl == GLAGLA)
    {
        sprite.load("://assets/sprites/t_donkeykong_ice.png");
    }
    else
    {
        sprite.load("://assets/sprites/t_donkeykong.png");
    }

    animation = new AnimationManager();
    animation->play(0, 6);

    throwingRate = 100; // The number of frames between each barrel thrown

    timer = throwingRate;

    isThrowing = false;

    hp = 3;
}


DonkeyKong::DonkeyKong(Coordinate pos, SceneType Lvl)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_donkeykong.png");

    animation = new AnimationManager();
    animation->play(0, 6);

    throwingRate = 100; // The number of frames between each barrel thrown

    timer = throwingRate;

    isThrowing = false;

    hp = 3;
}


DonkeyKong::~DonkeyKong()
{
    delete animation;
}


void DonkeyKong::update()
{
    animation->update();

    timer--;

    if (dynamic_cast<Scene*>(parent)->getItsSceneType() != LOOSE_SCREEN)
    {
        if(timer == 0)
        {
            // Only throws barrels
            if (dynamic_cast<Level*>(parent)->getItsSceneType() == ORIGINAL)
            {
                // Spawns a barrel
                dynamic_cast<Level*>(parent)->createEntity(new Barrel(pos.x + 2 * cellSize, pos.y + cellSize));

                // Chooses a random position
                int random = rand() % 18;
                targetPos = random * cellSize - cellSize;
            }

            // Also throws flames
            else if (dynamic_cast<Level*>(parent)->getItsSceneType() == RELOADED ||
                     dynamic_cast<Level*>(parent)->getItsSceneType() == TUTORIAL ||
                     dynamic_cast<Level*>(parent)->getItsSceneType() == BOMBERLAND)
            {
                if (rand() % 4 > 0)
                {
                    // Throws a barrel
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
                    // Throws a Flamme
                    dynamic_cast<Level*>(parent)->createEntity(new Flame(SpawnPos, pos.y));
                }
                pos.x = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == GLAGLA)
            {
                Coordinate spawnPos;
                spawnPos.x = rand() % 20 * cellSize;
                spawnPos.y = ((rand() % 60) + 4) * cellSize ;
                // Throws a Flamme
                dynamic_cast<Level*>(parent)->createEntity(new Barrel(spawnPos, pos.y));
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == CHOCHO)
            {
                Coordinate SpawnPos;
                SpawnPos.x = rand() % 20 * cellSize;
                SpawnPos.y = ((rand() % 60) + 4) * cellSize ;
                pos.x = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
                if(rand()%2 == 1)
                {
                    // Throws a Flamme
                    dynamic_cast<Level*>(parent)->createEntity(new Flame(SpawnPos, pos.y));
                }
                else
                {
                    dynamic_cast<Level*>(parent)->createEntity(new FireBall(dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x,pos.y,dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().y ));
                }
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == JUNGLEDK)
            {
                // Throwing bananas
                Coordinate bananaTargetPos;

                do
                {
                    bananaTargetPos = Coordinate(RNG::randomInt(0, 20), RNG::randomInt(-40, 20));
                } while (dynamic_cast<Level*>(parent)->isPointInWall(bananaTargetPos * cellSize));

                dynamic_cast<Level*>(parent)->createEntity(new Banana(pos, bananaTargetPos * cellSize));


                // Calling family
                Coordinate monkeyTargetPos;

                do
                {
                    monkeyTargetPos = Coordinate(RNG::randomInt(0, 20), RNG::randomInt(-40, 20));
                } while (dynamic_cast<Level*>(parent)->isPointInWall(monkeyTargetPos * cellSize));

                dynamic_cast<Level*>(parent)->createEntity(new Monkey(monkeyTargetPos * cellSize, "://assets/sprites/t_didikong.png"));
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == GLAGLA)
            {
                Coordinate SpawnPos;
                SpawnPos.x = rand() % 20 * cellSize;
                SpawnPos.y = ((rand() % 60) + 4) * cellSize ;
                pos.x = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
                if(rand() % 2 == 1)
                {
                    // Throws a Flamme
                    dynamic_cast<Level*>(parent)->createEntity(new BlueFlamme(SpawnPos, pos.y));
                }
                else
                {
                    dynamic_cast<Level*>(parent)->createEntity(new IceBloc(SpawnPos.x, pos.y + cellSize,SpawnPos.y));
                }
            }

            timer = throwingRate; // Reset the timer
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

            if(dynamic_cast<Level*>(parent)->getItsSceneType() == ORIGINAL)
            {
                // Move to target
                pos.x += (targetPos - pos.x) * 0.07;
            }
        }
    }
}


void DonkeyKong::draw(QPainter* painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
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


void DonkeyKong::collisionEvent(Entity* body)
{
    if (dynamic_cast<Explosion*>(body) != nullptr)
    {
        body->deleteEntity();

        hp--;
        if (hp == 0)
        {
            dynamic_cast<Level*>(parent)->win();
        }
    }
}
