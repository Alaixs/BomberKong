#ifndef BOMBERGIRL_H
#define BOMBERGIRL_H

#include "animationmanager.h"
#include "entity.h"

class BomberGirl : public Entity
{
public:

    /**
     * @brief Create a BomberGirl
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    BomberGirl(int posX, int posY);

    /**
     * @brief Create a BomberGirl
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    BomberGirl(Coordinate pos);

    /**
     * @brief update bombergirl (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual Bombergirl's sprite
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief Detect and react for the collision with other entities
     * @param body : the coordinate of the other entities
     */
    void collisionEvent(Entity * body);

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite;///< The actual Sprite
    AnimationManager animation;///< The actual animation ( the range in the sprite image)
};

#endif // BOMBERGIRL_H
