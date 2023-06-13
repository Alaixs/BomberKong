#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "entity.h"
#include "animationmanager.h"
#include "soundmanager.h"
#include "powerup.h"

/**
 * @brief The class of the Player's Character
 */
class PlayerCharacter : public Entity
{

private:
    QPixmap sprite;                 ///< The actual Sprite
    QPixmap hammerSprite;
    Coordinate motion;              ///< direction
    AnimationManager* animation;    ///< The actual animation ( the range in the sprite image)
    AnimationManager* hammerAnimation;

    bool flipped;                   ///< False = left, True = false
    bool isStunned;
    bool isKO;                      ///< is the character KO, he is not controllable if true
    int timer;                      ///< init timer
    int stunTimer;
    int nbLives;                    ///< The player's current lives count

    // Power-Up
    int speedBonusNb;               ///< The number of speed Power-Up the player currently has
    int maxBombBonusNb;             ///< The number of max bomb Power-Up the player currently has
    int explosionRangeBonusNb;      ///< The number of explosion range bonus Power-Up the player currently has
    int explosionTimeBonusNb;       ///< The number of explosion time bonus Power-Up the player currently has
    bool armorOn;                   ///< Bool to check if the player is currently wearing an armor
    int invincibilityTimer;         ///< A timer for the player invincibility after losing an armor
    int hammerTimer;

    int freeze;

public:
    bool isHammer;

    /**
     * @brief Create a playable character
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    PlayerCharacter(int posX, int posY);

    /**
     * @brief Create a playable character
     * @param pos : location coordinates
     */
    PlayerCharacter(Coordinate pos);

    /**
     * @brief Destructor for a PlayerCharacter object
     */
    ~PlayerCharacter();

    /**
     * @brief update bomberman (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual Bomberman's sprite
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief Detect and react for the collision with other entities
     * @param body : the coordinate of the other entities
     */
    void collisionEvent(Entity * body);

    /**
     * @brief Play the foot step sound
     */
    void footstepsSfx();

    /**
     * @brief StopAllSounds
     */
    void stopAllSounds();

    SoundManager* soundManager;///< All the sound use by this class

    int speed; ///< The number of pixels traveled each frame

    /**
     * @brief Create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

    /**
     * @brief Set the player bonus count to 0 for every Power-Up type
     */
    void initBonus();

    /**
     * @brief Init the player invincibility
     */
    void initInvincibility( int time);

    /**
     * @brief Return if the player have hammer
     * @return if hammer is posseded by player
     */
    bool isOnHammerEffect();

    /**
     * @brief Stuns the player.
     *
     * @param time : The duration of te stun
     */
    void stun(int time);

    /**
     * @param lifes : The player number of lifes
     * @param speedNb : The number of speed bonuses
     * @param bombNb : The number of bomb number bonuses
     * @param bombRange :The number of bomb range bonuses
     * @param bombTime : The number of explosion time bonuses
     * @param wearArmor : If the player is wearing an armor or not
     */
    void setItsStats(int lifes, int speedNb, int bombNb, int bombRange, int bombTime, bool wearArmor);

    /**
     * @brief Getter for a Power-Up number
     * @param powerUp : The type of the Power-Up number we want
     * @return The number of the Power-Up the player has from the PU Type
     */
    int getItsPUNumber(PowerUpType powerUp);

    /**
     * @brief Getter for the player number of lives
     * @return The player number of lives
     */
    int getItsLivesNb();
};

#endif // PLAYERCHARACTER_H
