#include "playercharacter.h"

#include <QMessageBox>
#include "hammer.h"
#include "soundmanager.h"
#include "input.h"
#include "global.h"
#include "level.h"
#include "bombergirl.h"
#include "indestructiblewall.h"
#include "tutorial.h"
#include "wall.h"
#include "bomb.h"
#include "barrel.h"
#include "explosion.h"
#include "powerup.h"


PlayerCharacter::PlayerCharacter(int posX, int posY)
    : Entity(posX, posY)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_bomberman.png");
    animation->play(0, 4);
    speed = 2;
    timer = 0;
    nbLives = 2;
    isKO = false;
    initBonus();
}


PlayerCharacter::PlayerCharacter(Coordinate pos)
    : Entity(pos)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_bomberman.png");
    animation->play(0, 4);
    speed = 2;
    timer = 0;
    nbLives = 2;
    isKO = false;
    initBonus();
}

void PlayerCharacter::initBonus()
{
    speedBonusNb = 0;
    maxBombBonusNb = 0;
    explosionRangeBonusNb = 0;
    explosionTimeBonusNb = 0;
    armorOn = false;
    invincibilityTimer = 0;
}

void PlayerCharacter::initInvincibility(int time)
{
    invincibilityTimer = time;
}

PlayerCharacter::~PlayerCharacter()
{
    delete animation;
}

void PlayerCharacter::update()
{
    dynamic_cast<Scene*>(parent)->setCameraOffset(pos); // Manage the scrolling

    animation->update();

    if (!isKO) // If the player is controllable
    {

    if (Input::isActionPressed(MOVE_RIGHT)) { motion.x = 1+(speedBonusNb*0.20); flipped = true; footstepsSfx(); }
    else if (Input::isActionPressed(MOVE_LEFT)) { motion.x = -(1+speedBonusNb*0.20); flipped = false; footstepsSfx(); }
    else { motion.x = 0; }

    if (Input::isActionPressed(MOVE_DOWN)) { motion.y = 1+speedBonusNb*0.20; footstepsSfx(); }
    else if (Input::isActionPressed(MOVE_UP)) { motion.y = -(1+speedBonusNb*0.20); footstepsSfx(); }
    else { motion.y = 0; }

    if(Input::isActionPressed(PLACE_BOMB) && invincibilityTimer == 0)
    {
        if(dynamic_cast<Level*>(parent)->getBombOnScreenNb() < 1+maxBombBonusNb)
        {
            if (timer < 0)
            {
            // Place the bomb in the center of a cell
            Coordinate bombPos(pos);
            bombPos.x = ((bombPos.x + cellSize / 2) / cellSize) * cellSize;
            bombPos.y = ((bombPos.y + cellSize / 2) / cellSize) * cellSize;
            dynamic_cast<Level*>(parent)->createEntity(new Bomb(bombPos,1+explosionRangeBonusNb, 1+explosionTimeBonusNb));

            // Reset the cooldown timer
            timer = 14;

            dynamic_cast<Level*>(parent)->incrementBombNb();
            }
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
        if (nbLives > -1)
        {
            // Restart the current level if the player still have a life
            // Go all the way back to the tutorial otherwise
            dynamic_cast<Level*>(parent)->restart();

            if (dynamic_cast<Level*>(parent)->getItsSceneType() != ORIGINAL) // Reset the Power-Up GUI and bonuses
            {
                initBonus(); // Reset the player bonuses
                std::list<PowerUpType> types = {SPEED, BOMB_NB, BOMB_RANGE, BOMB_TIME, ARMOR};
                for (std::list<PowerUpType>::iterator it = types.begin(); it != types.end(); it++)
                {
                    dynamic_cast<Level*>(parent)->updatePowerUpGUI(0, (*it));
                }
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

    if (!armorOn && invincibilityTimer != 0) // Decrease the invincibility time
    {
        invincibilityTimer--;
        if(invincibilityTimer % 10 == 0 && invincibilityTimer > 50)
        {
            dynamic_cast<Level*>(parent)->createExplosion(pos.x,pos.y);
        }
    }

}

void PlayerCharacter::collisionEvent(Entity * body)
{
    // Collision with walls
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

    // Collision with a Power-Up
    if (dynamic_cast<PowerUp*>(body) != nullptr)
    {
        switch(dynamic_cast<PowerUp*>(body)->getItsType())
        {
        case SPEED: // Collecting a speed bonus
            speedBonusNb++;
            dynamic_cast<PowerUp*>(body)->collected();
            dynamic_cast<Level*>(parent)->updatePowerUpGUI(speedBonusNb, SPEED);
            break;

        case BOMB_NB: // Collecting a max bomb bonus
            maxBombBonusNb++;
            dynamic_cast<PowerUp*>(body)->collected();
            dynamic_cast<Level*>(parent)->updatePowerUpGUI(maxBombBonusNb, BOMB_NB);
            break;

        case BOMB_RANGE: // Collecting a bomb range bonus
            if (explosionRangeBonusNb < 5)
            {
                explosionRangeBonusNb++;
                dynamic_cast<PowerUp*>(body)->collected();
                dynamic_cast<Level*>(parent)->updatePowerUpGUI(explosionRangeBonusNb, BOMB_RANGE);
            }
            break;

        case BOMB_TIME: // Collecting an explosion time bonus
            if (explosionTimeBonusNb < 4)
            {
                explosionTimeBonusNb++;
                dynamic_cast<PowerUp*>(body)->collected();
                dynamic_cast<Level*>(parent)->updatePowerUpGUI(explosionTimeBonusNb, BOMB_TIME);
            }
            break;

        case ARMOR: // Collecting an armor
            if (!armorOn)
            {
                armorOn = true;
                invincibilityTimer = 0;
                dynamic_cast<PowerUp*>(body)->collected();
                dynamic_cast<Level*>(parent)->updatePowerUpGUI(1, ARMOR);
            }
            break;

        default:
            break;
        }
    }

    if(dynamic_cast<Hammer*>(body) != nullptr)
    {
        initInvincibility(400);
        dynamic_cast<Hammer*>(body)->deleteEntity();
    }

    // Collision with damaging entities
    if (dynamic_cast<Barrel*>(body) != nullptr || dynamic_cast<Explosion*>(body) != nullptr || dynamic_cast<Flame*>(body) != nullptr)
    {
        if (invincibilityTimer == 0)
        {
            if (!armorOn) // The player can't take damage if he's wearing the armor or is invincible
            {
                if (isKO) { return; } // Doesn't take damage if already KO

                nbLives--;
                isKO = true;

                dynamic_cast<Level*>(parent)->updateLivesGUI(nbLives); // Called the parent element to change the lives GUI
                dynamic_cast<Level*>(parent)->resetBombOnScreenNb(); // Reset the number of bomb on the screen to 0
            }
            else
            {
                armorOn = false; // The player looses his armor
                initInvincibility(200); // The player has some frames of invincibility
                dynamic_cast<Level*>(parent)->updatePowerUpGUI(0, ARMOR); // Hide the armor GUI
            }
        }
    }

    // Collision with BomberGirl
    if (dynamic_cast<BomberGirl*>(body) != nullptr)
    {
        dynamic_cast<Level*>(parent)->win();
    }

    // Collision with a Bomb
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
        Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite,
            QRect(animation->getFrame() * 16, 0, 16, 16)
        );
    }
    else
    {
        // Draw the flipped sprite
        Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((11 - animation->getFrame()) * 16, 0, 16, 16)
        );
    }
}

void PlayerCharacter::footstepsSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_footsteps.wav", 0.5, false);
}

QRect PlayerCharacter::getRect()
{
    return QRect(pos.x , pos.y, cellSize - 2, cellSize);
}

bool PlayerCharacter::isOnHammerEffect()
{
    return isHammer;
}
