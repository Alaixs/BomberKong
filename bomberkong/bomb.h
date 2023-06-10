#ifndef BOMB_H
#define BOMB_H

#include "entity.h"
#include "animationmanager.h"
#include "soundmanager.h"

/**
 * @brief The class of bomb place by BomberMan
 */
class Bomb : public Entity
{
    int timer;                     ///< The number of frame the bomb will stay, also use to switch frame and explode
    QPixmap sprite;                 ///< The actual Sprite
    AnimationManager* animation;    ///< The actual animation ( the range in the sprite image)
    SoundManager* soundManager;     ///< The explosion's sound
    int itsExplosionRange;          ///< The range of the explosion
    int itsExplosionTime;              ///< The time before the bomb explode (NOT in second)

public:
    /**
     * @brief Create a Bomb
     * @param posX : position on x axes
     * @param posY : position on y axes
     * @param explosionRange : The range of the explosion
     * @param explosionTime : The time before the bomb explode (NOT in second)
     */
    Bomb(int posX, int posY, int explosionRange, int explosionTime);

    /**
     * @brief Create a Bomb
     * @param posX : position on x axes
     * @param posY : position on y axes
     * @param explosionRange : The range of the explosion
     * @param explosionTime : The time before the bomb explode (NOT in second)
     */
    Bomb(Coordinate position, int explosionRange, int explosionTime);

    /**
     * @brief Destructor for a Bomb object
     */
    ~Bomb();

    /**
     * @brief update the bomb (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual bomb
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief Detect and react for the collision with other entities
     * @param body : the coordinate of the other entities
     */
    void collisionEvent(Entity * body);

    /**
     * @brief make a sound for the explosion
     */
    void explosionSfx();

    /**
     * @brief create the hitboxe of the bomb
     * @return the hitboxe
     */
    QRect getRect();

};

#endif // BOMB_H
