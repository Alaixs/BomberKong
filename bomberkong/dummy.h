#ifndef DUMMY_H
#define DUMMY_H

#include "entity.h"
#include "animationmanager.h"
#include "soundmanager.h"

class Dummy : public Entity
{
public:

    /**
     * @brief Create a no playable Bomberman
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Dummy(int posX, int posY);

    /**
     * @brief Create a no playable Bomberman
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Dummy(Coordinate pos);

    /**
     * @brief update the bomberman (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual bomberman
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief make a sound for the defeat
     */
    void loseThemeSfx();

    /**
     * @brief Stop all the Sound
     */
    void stopAllSounds();


    SoundManager* soundManager; ///< The defeat's sound

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite;///< The actual Sprite
    AnimationManager animation; ///< The actual animation
    int timer; ///< init timer
};

#endif // DUMMY_H
