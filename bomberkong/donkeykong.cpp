#include "donkeykong.h"

#include <random>
#include "blueflamme.h"
#include "fireball.h"
#include "global.h"
#include "icebloc.h"
#include "jungle.h"
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
                if (RNG::randomInt(0, 3) > 0)
                {
                    // Throws a barrel
                    dynamic_cast<Level*>(parent)->createEntity(new Barrel(pos.x + 2 * cellSize, pos.y + cellSize, dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().y));
                }
                else
                {
                    Coordinate SpawnPos;
                    if(dynamic_cast<Level*>(parent)->getItsSceneType() == TUTORIAL)
                    {
                        if(RNG::randomInt(0, 1) == 0)
                         {
                            SpawnPos.x = RNG::randomInt(0, 9) * cellSize;
                            SpawnPos.y = RNG::randomInt(13, 22) * cellSize ;
                        }
                        else
                        {
                            SpawnPos.x = RNG::randomInt(10, 19) * cellSize;
                            SpawnPos.y = RNG::randomInt(3, 12) * cellSize ;
                        }
                    }
                    else
                    {
                        SpawnPos.x = RNG::randomInt(0, 19) * cellSize;
                        SpawnPos.y = RNG::randomInt(4, 63) * cellSize ;
                    }
                    // Throws a Flamme
                    dynamic_cast<Level*>(parent)->createEntity(new Flame(SpawnPos, pos.y));
                }
                targetPos = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == GLAGLA)
            {
                Coordinate spawnPos;
                spawnPos.x = RNG::randomInt(0, 19) * cellSize;
                spawnPos.y = RNG::randomInt(4, 63) * cellSize ;
                // Throws a Flamme
                dynamic_cast<Level*>(parent)->createEntity(new Barrel(spawnPos, pos.y));
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == CHOCHO)
            {
                Coordinate SpawnPos;
                SpawnPos.x = RNG::randomInt(0, 19) * cellSize;
                SpawnPos.y = RNG::randomInt(4, 63) * cellSize ;
                targetPos = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
                if(RNG::randomInt(0, 1) == 1)
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

                int yMin = 20;
                if(dynamic_cast<Jungle*>(parent)->isBossRoomClose)
                {
                    yMin = -30;
                }

                do
                {
                    monkeyTargetPos = Coordinate(RNG::randomInt(0, 20), RNG::randomInt(-38, yMin));
                } while (dynamic_cast<Level*>(parent)->isPointInWall(monkeyTargetPos * cellSize));
                int random = RNG::randomInt(0, 2);
                if(random == 0)
                {
                    dynamic_cast<Level*>(parent)->createEntity(new Monkey(monkeyTargetPos * cellSize, "://assets/sprites/t_didikong.png"));
                }
                else if(random == 1)
                {
                    dynamic_cast<Level*>(parent)->createEntity(new Monkey(monkeyTargetPos * cellSize, "://assets/sprites/t_dadakong.png"));
                }
                else
                {
                    dynamic_cast<Level*>(parent)->createEntity(new Monkey(monkeyTargetPos * cellSize, "://assets/sprites/t_funkykong.png"));
                }
            }
            else if(dynamic_cast<Level*>(parent)->getItsSceneType() == GLAGLA)
            {
                Coordinate SpawnPos;
                SpawnPos.x = RNG::randomInt(0, 19) * cellSize;
                SpawnPos.y = RNG::randomInt(4, 63) * cellSize ;
                targetPos = dynamic_cast<Level*>(parent)->getItsPlayer()->getPos().x - 2 * cellSize;
                if(RNG::randomInt(0, 1) == 1)
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

            // Move to target
            pos.x += (targetPos - pos.x) * 0.07;
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
