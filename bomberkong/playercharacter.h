#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "entity.h"
#include "animationmanager.h"
#include "soundmanager.h"


class PlayerCharacter : public Entity
{

public:

    /**
     * @brief Create a playable character
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    PlayerCharacter(int posX, int posY);

    /**
     * @brief Create a playable character
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    PlayerCharacter(Coordinate pos);

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
     * @brief Play the lose sound
     */
    void loseThemeSfx();

    /**
     * @brief Play the win sound
     */
    void winThemeSfx();

    /**
     * @brief stopAllSounds
     */
    void stopAllSounds();

    SoundManager* soundManager;///< All the sound use by this class

    int speed; ///< The number of pixels traveled each frame

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite;///< The actual Sprite
    Coordinate motion;///< direction
    AnimationManager animation;///< The actual animation ( the range in the sprite image)

    bool flipped; ///< False = left, True = false
    int timer; ///< init timer

};

#endif // PLAYERCHARACTER_H
