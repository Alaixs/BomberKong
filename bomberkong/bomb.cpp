#include "bomb.h"

#include "global.h"
#include "input.h"
#include "level.h"
#include "wall.h"
#include "playercharacter.h"
#include "coordinate.h"
#include "indestructiblewall.h"


Bomb::Bomb(int posX, int posY, int explosionRange, int explosionTime)
    : Entity(posX, posY)
{
    animation = new AnimationManager();
    animation->play(0, 2);

    sprite.load("://assets/sprites/t_bomb.png");

    itsExplosionRange = explosionRange;
    itsExplosionTime = explosionTime;

    timer = 187 - explosionTime * 31;
}


Bomb::Bomb(Coordinate position, int explosionRange, int explosionTime)
    : Entity(position)
{
    animation = new AnimationManager();
    animation->play(0, 2);

    sprite.load("://assets/sprites/t_bomb.png");

    itsExplosionRange = explosionRange;
    itsExplosionTime = explosionTime;

    timer = 187 - explosionTime * 31;
}


Bomb::~Bomb()
{
    delete animation;
}


void Bomb::update()
{
    animation->update();
    timer--;

    // Final second, plays the flashing animation
    if (timer <= 62)
    {
        animation->play(2, 4);
    }

    // Create explosions in a + pattern around the bomb and disappear
    if (timer <= 0)
    {
        qDebug() << itsExplosionRange;
        // Keep track of how many bomb exists to prevent the player from placing too many of them
        dynamic_cast<Level*>(parent)->decrementBombNb();

        dynamic_cast<Level*>(parent)->createExplosion(pos.x, pos.y);

        // Up
        for (int i = 1; i <= itsExplosionRange; i++)
        {
            Coordinate explosionPos(pos.x, pos.y + cellSize * i);

            dynamic_cast<Level*>(parent)->createExplosion(explosionPos.x, explosionPos.y);

            if (dynamic_cast<Level*>(parent)->isPointInWall(explosionPos))
            {
                break;
            }
        }

        // Down
        for (int i = 1; i <= itsExplosionRange; i++)
        {
            Coordinate explosionPos(pos.x, pos.y - cellSize * i);

            dynamic_cast<Level*>(parent)->createExplosion(explosionPos.x, explosionPos.y);

            if (dynamic_cast<Level*>(parent)->isPointInWall(explosionPos))
            {
                break;
            }
        }

        // Left
        for (int i = 1; i <= itsExplosionRange; i++)
        {
            Coordinate explosionPos(pos.x - cellSize * i, pos.y);

            dynamic_cast<Level*>(parent)->createExplosion(explosionPos.x, explosionPos.y);

            if (dynamic_cast<Level*>(parent)->isPointInWall(explosionPos))
            {
                break;
            }
        }

        // Right
        for (int i = 1; i <= itsExplosionRange; i++)
        {
            Coordinate explosionPos(pos.x + cellSize * i, pos.y);

            dynamic_cast<Level*>(parent)->createExplosion(explosionPos.x, explosionPos.y);

            if (dynamic_cast<Level*>(parent)->isPointInWall(explosionPos))
            {
                break;
            }
        }

        explosionSfx();

        deleteEntity();
    }
}


void Bomb::collisionEvent(Entity * body){
    // Is pushed away when colliding with walls or the player

    // Calculates on which axis the bomb is the closest to the collider and push it back on this axis
    // This method allows a "sliding" movement. Otherwise, the bomb wont move as soon as it touches a
    // wall, even if it only slides along it.

    if((dynamic_cast<PlayerCharacter*>(body) != nullptr && Input::isActionPressed(PUSH_BOMB)))
    {
        int distX = pos.x - body->getPos().x;
        int distY = pos.y - body->getPos().y;

        if (abs(distX) > abs(distY))
        {
            pos.x += (distX / abs(distX)) * dynamic_cast<PlayerCharacter*>(body)->speed ;
        }
        else
        {
            pos.y += (distY / abs(distY)) * dynamic_cast<PlayerCharacter*>(body)->speed;

        }
    }

    if(dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
    {
        int distX = pos.x - body->getPos().x ;
        int distY = pos.y - body->getPos().y;

        if (abs(distX) > abs(distY))
        {
            pos.x += (distX / abs(distX)) * 2;
        }
        else
        {
            pos.y += (distY / abs(distY)) * 2;
        }
    }
}


void Bomb::draw(QPainter * painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
    );
}


void Bomb::explosionSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_explosion.wav", 0.5, false);
}



QRect Bomb::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
