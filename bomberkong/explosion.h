#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "animationmanager.h"
#include "entity.h"

class Explosion : public Entity
{

public:

    /**
     * @brief Create an explosion
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Explosion(int posX, int posY);

    /**
     * @brief Create an explosion
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Explosion(Coordinate position);

    /**
     * @brief update the explosion (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual explosion
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite;///< The actual Sprite
    AnimationManager animation;///< The actual animation
    int timer = 12;///< explosion duration

};

#endif // EXPLOSION_H
