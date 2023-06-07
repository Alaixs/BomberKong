#ifndef WALL_H
#define WALL_H

#include "entity.h"


class Wall : public Entity
{

public:

    /**
     * @brief Create a no playable wall
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Wall(int posX, int posY);

    /**
     * @brief Create a no playable wall
     * @param pos : location coordinates
     */
    Wall(Coordinate pos);

    /**
<<<<<<< HEAD
     * @brief Destructor for a Wall object
     */
    ~Wall();

    /**
     * @brief update the wall (position, sprite, etc)
=======
     * @brief Update the wall (position, sprite, etc)
>>>>>>> b0c16029fa8c3708a236a486d2db051be62ca586
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
     * @brief Create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite;///< The actual Sprite

};

#endif // WALL_H
