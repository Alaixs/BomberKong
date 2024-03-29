#ifndef WALL_H
#define WALL_H

#include "entity.h"


class Wall : public Entity
{
    QPixmap sprite; ///< The actual Sprite

public:
    /**
     * @brief Create a no playable wall
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Wall(int posX, int posY, SceneType Lvl);

    /**
     * @brief Create a no playable wall
     * @param pos : location coordinates
     */
    Wall(Coordinate pos, SceneType Lvl);

    /**
     * @brief Destructor for a Wall object
     */
    ~Wall();

    /**
     * @brief update the wall (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual bomberman
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief Detect and react for the collision with other entities
     * @param body : the coordinate of the other entities
     */
    void collisionEvent(Entity * body);

    /**
     * @brief Create the hitbox
     * @return the hitbox
     */
    QRect getRect();

    /**
     * @brief 20% of chance for the wall to drop a Power-Up
     */
    void dropPowerUp();

};

#endif // WALL_H
