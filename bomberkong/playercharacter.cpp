
#include "playercharacter.h"

#include <QMessageBox>
#include "bombergirl.h"
#include "indestructiblewall.h"
#include "input.h"
#include "wall.h"
#include "bomb.h"
#include "barrel.h"
#include "explosion.h"
#include "soundmanager.h"
#include "global.h"
#include "game.h"


PlayerCharacter::PlayerCharacter(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomberman.png");
    animation.play(0, 4);
    speed = 2;
    timer = 0;
    nbLive = 2;
    isKO = false;
}


PlayerCharacter::PlayerCharacter(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bomberman.png");
    animation.play(0, 4);
    speed = 2;
    timer = 0;
    nbLive = 2;
    isKO = false;
}


void PlayerCharacter::update()
{
    animation.update();

    if (Input::isActionJustPressed(START))
    {
        qDebug() << "Ratio aleks";
    }

    if (!isKO)
    {

    if (Input::isActionPressed(MOVE_RIGHT)) { motion.x = 1; flipped = true; footstepsSfx(); }
    else if (Input::isActionPressed(MOVE_LEFT)) { motion.x = -1; flipped = false; footstepsSfx(); }
    else { motion.x = 0; }

    if (Input::isActionPressed(MOVE_DOWN)) { motion.y = 1; footstepsSfx(); }
    else if (Input::isActionPressed(MOVE_UP)) { motion.y = -1; footstepsSfx(); }
    else { motion.y = 0; }

    if(Input::isActionPressed(PLACE_BOMB))
    {
        if(timer < 0)
        {
            Coordinate bombPos(pos);
            bombPos.x = ((bombPos.x + cellSize / 2) / cellSize) * cellSize;
            bombPos.y = ((bombPos.y + cellSize / 2) / cellSize) * cellSize;
            dynamic_cast<Game*>(parent)->createEntity(new Bomb(bombPos));
            //qDebug() << "coubeh";
            timer = 200;
        }
    }

    if(pos.y > 25 * cellSize){

        //dynamic_cast<Game*>(parent)->alternative();
    }

    pos += motion * speed;
    if(timer >= 0)
        timer--;

    if (abs(motion.x) > 0 || abs(motion.y) > 0)
    {
        animation.play(4, 8);
    }
    else
    {
        animation.play(0, 4);
    }

    }
    else
    {

    animation.play(10, 12);

    if (Input::isActionPressed(MOVE_DOWN))
    {
        if (nbLive > -1)
        {
            dynamic_cast<Game*>(parent)->restart();
            pos.x = 9.5 * cellSize;
            pos.y = 21 * cellSize;
            isKO = false;
        }
        else
        {
            dynamic_cast<Game*>(parent)->loose();
        }
    }

    }

}


void PlayerCharacter::collisionEvent(Entity * body)
{
    if (dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
    {
        // Offsets the player away from the collider
        int distX = pos.x - body->getPos().x;
        int distY = pos.y - body->getPos().y;

        if (abs(distX) > abs(distY))
        {
            pos.x += (distX / abs(distX)) * speed;
        }
        else
        {
            pos.y += (distY / abs(distY)) * speed;

        }
    }

    if (dynamic_cast<Barrel*>(body) != nullptr || dynamic_cast<Explosion*>(body) != nullptr)
    {
        if (isKO) { return; }

        nbLive--;

        isKO = true;
    }

    if (dynamic_cast<BomberGirl*>(body) != nullptr)
    {
        dynamic_cast<Game*>(parent)->win();
    }

    if(dynamic_cast<Bomb*>(body) != nullptr)
    {
        if(Input::isActionPressed(PUSH_BOMB) == false)
        {
            // Offsets the player away from the collider
            int distX = pos.x - body->getPos().x;
            int distY = pos.y - body->getPos().y;

            if (abs(distX) > abs(distY))
            {
                pos.x += (distX / abs(distX)) * speed;
            }
            else
            {
                pos.y += (distY / abs(distY)) * speed;
            }
        }
    }
}




void PlayerCharacter::draw(QPainter * painter)
{
    if (!flipped)
    {
        // Draw the normal sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, cellSize, cellSize),
            sprite,
            QRect(animation.getFrame() * 16, 0, 16, 16)
        );
    }
    else
    {
        // Draw the flipped sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((11 - animation.getFrame()) * 16, 0, 16, 16)
        );
    }
}

void PlayerCharacter::footstepsSfx()
{
   // SoundManager::getInstance().playSound("://assets/sounds/sfx_footsteps.wav", 0.5);
}

void PlayerCharacter::loseThemeSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_loseTheme.wav", 0.5);
}

void PlayerCharacter::winThemeSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_winTheme.wav", 0.5);
}


QRect PlayerCharacter::getRect()
{
    return QRect(pos.x , pos.y, cellSize - 2, cellSize);
}
