#include "playercharacter.h"

#include <QMessageBox>
#include "blueflamme.h"
#include "fireball.h"
#include "hammer.h"
#include "icebloc.h"
#include "soundmanager.h"
#include "input.h"
#include "global.h"
#include "level.h"
#include "bombergirl.h"
#include "indestructiblewall.h"
#include "wall.h"
#include "bomb.h"
#include "barrel.h"
#include "explosion.h"
#include "powerup.h"


PlayerCharacter::PlayerCharacter(int posX, int posY)
    : Entity(posX, posY)
{
    // Character
    sprite.load("://assets/sprites/t_bomberman.png");
    animation = new AnimationManager();   
    animation->play(0, 4);

    // Hammer
    hammerSprite.load("://assets/sprites/t_hammer_Items.png");
    hammerAnimation = new AnimationManager();
    hammerAnimation->play(0,2);

    timer = 0;

    speed = 2;

    hammerTimer = 0;

    nbLives = 2;

    isStunned = false;

    isKO = false;
    isHammer = false;

    initBonus();

    freeze = 0;
}


PlayerCharacter::PlayerCharacter(Coordinate pos)
    : Entity(pos)
{
    // Character
    sprite.load("://assets/sprites/t_bomberman.png");
    animation = new AnimationManager();
    animation->play(0, 4);

    // Hammer
    hammerSprite.load("://assets/sprites/t_hammer_Items.png");
    hammerAnimation = new AnimationManager();
    hammerAnimation->play(0,2);

    timer = 0;

    speed = 2;

    hammerTimer = 0;

    isStunned = false;

    nbLives = 2;

    isKO = false;
    isHammer = false;

    initBonus();

    freeze = 0;
}

void PlayerCharacter::initBonus()
{
    // Reset every bonus to 0
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
    hammerAnimation->update();

    if (isKO)
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
    else if (isStunned)
    {
        animation->play(10, 12); // KO Animation
        stunTimer--;
        if (stunTimer == 0)
        {
            isStunned = false;
        }
    }
    else
    {
        // Sets the player motion according to keyboard inputs
        if (Input::isActionPressed(MOVE_RIGHT))
        {
            motion.x = 1;
            flipped = true;
            footstepsSfx();
        }
        else if (Input::isActionPressed(MOVE_LEFT))
        {
            motion.x = -1;
            flipped = false;
            footstepsSfx();
        }
        else
        {
            motion.x = 0;
        }

        if (Input::isActionPressed(MOVE_DOWN))
        {
            motion.y = 1;
            footstepsSfx();
        }
        else if (Input::isActionPressed(MOVE_UP))
        {
            motion.y = -1;
            footstepsSfx();
        }
        else
        {
            motion.y = 0;
        }

        if(Input::isActionPressed(PLACE_BOMB) && hammerTimer == 0)
        {
            if(dynamic_cast<Level*>(parent)->getBombOnScreenNb() < 1 + maxBombBonusNb)
            {
                if (timer < 0)
                {
                    // Place the bomb in the center of a cell
                    Coordinate bombPos(pos);
                    bombPos.x = (((int) bombPos.x + cellSize / 2) / cellSize) * cellSize;
                    bombPos.y = (((int) bombPos.y + cellSize / 2) / cellSize) * cellSize;
                    qDebug() << bombPos.x;
                    dynamic_cast<Level*>(parent)->createEntity(new Bomb(bombPos, 1 + explosionRangeBonusNb, 1 + explosionTimeBonusNb));

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

        // Updates position
        pos += motion * speed * ((speedBonusNb * 0.2) + 1);

        if(timer >= 0)
        {
            timer--;
        }

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

    if (!armorOn ) // Decrease the invincibility time
    {
        invincibilityTimer--;

        if(isHammer != true)
        {
            if(invincibilityTimer % 40 == 0)
            {
                sprite.load("://assets/sprites/t_bomberman.png");
            }
            else if(invincibilityTimer % 40 == 20)
            {
                sprite.load(":");
            }
        }
    }

    if(hammerTimer > 0)
    {
        hammerTimer--;
    }

    if(hammerTimer == 0 && isHammer == true)
    {
        isHammer = false;
    }
}

void PlayerCharacter::collisionEvent(Entity * body)
{
    if(dynamic_cast<Wall*>(body) != nullptr && isHammer)
    {
        dynamic_cast<Wall*>(body)->dropPowerUp();
        dynamic_cast<Wall*>(body)->deleteEntity();
    }

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
            if(speedBonusNb < 4 )
            {
                speedBonusNb++;
                dynamic_cast<PowerUp*>(body)->collected();
                dynamic_cast<Level*>(parent)->updatePowerUpGUI(speedBonusNb, SPEED);
            }
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
        hammerTimer = 400;
        isHammer = true;
        dynamic_cast<Hammer*>(body)->deleteEntity();
    }

    // Collision with damaging entities
    if ((dynamic_cast<Level*>(parent)->getItsSceneType() != ORIGINAL && dynamic_cast<Barrel*>(body) != nullptr && !(dynamic_cast<Barrel*>(body)->getIsFlying()))
        || (dynamic_cast<Level*>(parent)->getItsSceneType() == ORIGINAL && dynamic_cast<Barrel*>(body) != nullptr)
        || dynamic_cast<Explosion*>(body) != nullptr
        || dynamic_cast<Flame*>(body) != nullptr
        || dynamic_cast<BlueFlamme*>(body) != nullptr
        || (dynamic_cast<FireBall*>(body) != nullptr
            && !(dynamic_cast<FireBall*>(body)->getIsFlying()
                 )
            )
        )
    {
        if (invincibilityTimer <= 0 && hammerTimer == 0)
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
    if(dynamic_cast<IceBloc*>(body) != nullptr )
    {
        freeze++;

        if(freeze == 300)
        {
            nbLives--;
            isKO = true;
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
        // Draws the normal sprite
        Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite,
            QRect(animation->getFrame() * 16, 0, 16, 16)
        );

        // Draws the hammer
        if(isHammer)
        {
            Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
            painter->drawPixmap(
                QRect(pos.x - 16, pos.y - offset.y + 416, cellSize, cellSize),
                hammerSprite,
                QRect(hammerAnimation->getFrame() * 16, 0, 16, 16)
                );
        }

    }
    else
    {
        // Draws the flipped sprite
        Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
        painter->drawPixmap(
            QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((12 - animation->getFrame()) * 16, 0, 16, 16)
        );

        // Draws the hammer
        if(isHammer)
        {
            Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
            painter->drawPixmap(
                QRect(pos.x + 16, pos.y  - offset.y + 416, cellSize, cellSize),
                hammerSprite.transformed(QTransform().scale(-1, 1)),
                QRect(hammerAnimation->getFrame() * 16, 0, 16, 16)
                );
        }
    }


}

void PlayerCharacter::footstepsSfx()
{
    dynamic_cast<Level*>(parent)->updateLivesGUI(nbLives);
    std::cout << nbLives << std::endl;
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


void PlayerCharacter::stun(int time)
{
    isStunned = true;
    stunTimer = time;
}


void PlayerCharacter::setItsStats(int lifes, int speedNb, int bombNb, int bombRange, int bombTime, bool wearArmor)
{
    nbLives = lifes;
    speedBonusNb = speedNb;
    maxBombBonusNb = bombNb;
    explosionRangeBonusNb = bombRange;
    explosionTimeBonusNb = bombTime;
    armorOn = wearArmor;
}


int PlayerCharacter::getItsPUNumber(PowerUpType powerUp)
{
    switch(powerUp)
    {
    case SPEED:
        return speedBonusNb;

    case BOMB_NB:
        return maxBombBonusNb;

    case BOMB_RANGE:
        return explosionRangeBonusNb;

    case BOMB_TIME:
        return explosionTimeBonusNb;

    case ARMOR:
        return armorOn;

    default:
        break;
    }
}


int PlayerCharacter::getItsLivesNb()
{
    return nbLives;
}
