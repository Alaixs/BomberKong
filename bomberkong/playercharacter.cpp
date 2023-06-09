#include "playercharacter.h"

#include <QMessageBox>
#include "soundmanager.h"
#include "input.h"
#include "global.h"
#include "game.h"
#include "bombergirl.h"
#include "indestructiblewall.h"
#include "tutorial.h"
#include "wall.h"
#include "bomb.h"
#include "barrel.h"
#include "explosion.h"


int wLvl;

PlayerCharacter::PlayerCharacter(int posX, int posY)
    : Entity(posX, posY)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_bomberman.png");
    animation->play(0, 4);
    speed = 2;
    timer = 0;
    nbLive = 2;
    isKO = false;
}


PlayerCharacter::PlayerCharacter(Coordinate pos)
    : Entity(pos)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_bomberman.png");
    animation->play(0, 4);
    speed = 2;
    timer = 0;
    nbLive = 2;
    isKO = false;
}


PlayerCharacter::~PlayerCharacter()
{
    delete animation;
}


void PlayerCharacter::update()
{
    animation->update();

    if (!isKO) // If the player is controllable
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
            // Place the bomb in the center of a cell
            Coordinate bombPos(pos);
            bombPos.x = ((bombPos.x + cellSize / 2) / cellSize) * cellSize;
            bombPos.y = ((bombPos.y + cellSize / 2) / cellSize) * cellSize;
            dynamic_cast<Level*>(parent)->createEntity(new Bomb(bombPos));

            // Reset the cooldown timer
            timer = 200;
        }
    }

    if(pos.y > 25 * cellSize)
    {
        // Triggers the alternative ending
        dynamic_cast<Level*>(parent)->alternative();
    }

    pos += motion * speed;

    if(timer >= 0)
        timer--;

    // Plays the running animation if the player is moving
    if (abs(motion.x) > 0 || abs(motion.y) > 0)
    {
        animation->play(4, 8);
    }
    else
    {
        animation->play(0, 4);
    }

    }
    else // Player is KO
    {

    animation->play(10, 12); // KO Animation

    if (Input::isActionJustPressed(START))
    {
        if (nbLive > -1)
        {
            // Restart the current level if the player still have a life
            // Go all the way back to the tutorial otherwise
            if( wLvl == 1)
            {
                dynamic_cast<Level*>(parent)->restart();
            }
            else
            {
                dynamic_cast<Tutorial*>(parent)->restart();
            }
            pos.x = 9.5 * cellSize;
            pos.y = 21 * cellSize;
            isKO = false;
        }
        else
        {
            dynamic_cast<Level*>(parent)->loose();
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
            pos.x += (distX / abs(distX)) * speed;
        else
            pos.y += (distY / abs(distY)) * speed;
    }

    if (dynamic_cast<Barrel*>(body) != nullptr || dynamic_cast<Explosion*>(body) != nullptr)
    {
        if (isKO) { return; } // Doesn't take damage if already KO

        nbLive--;
        isKO = true;
    }

    if (dynamic_cast<BomberGirl*>(body) != nullptr)
    {
        if( wLvl == 1)
        {
            dynamic_cast<Level*>(parent)->win();
        }
        else
        {
            wLvl = 1;
            dynamic_cast<Tutorial*>(parent)->nextLvl();
        }
    }

    if(dynamic_cast<Bomb*>(body) != nullptr)
    {
        if(Input::isActionPressed(PUSH_BOMB) == false)
        {
            // Offsets the player away from the collider
            int distX = pos.x - body->getPos().x;
            int distY = pos.y - body->getPos().y;

            if (abs(distX) > abs(distY))
                pos.x += (distX / abs(distX)) * speed;
            else
                pos.y += (distY / abs(distY)) * speed;
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
            QRect(animation->getFrame() * 16, 0, 16, 16)
        );
    }
    else
    {
        // Draw the flipped sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((11 - animation->getFrame()) * 16, 0, 16, 16)
        );
    }
}

void PlayerCharacter::footstepsSfx()
{
    //SoundManager::getInstance().playSound("://assets/sounds/sfx_footsteps.wav", 0.5);
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
