#ifndef INDESTRUCTIBLEWALL_H
#define INDESTRUCTIBLEWALL_H

#include "entity.h"


/**
 * @brief The class of Indestructible Wall
 */
class IndestructibleWall : public Entity
{

public:
    /**
     * @brief Create a Indestructible wall
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    IndestructibleWall(int posX, int posY, SceneType Lvl);

    /**
     * @brief Create a Indestructible wall
     * @param pos : location coordinates
     */
    IndestructibleWall(Coordinate pos, SceneType Lvl);

    /**
     * @brief Destructor for an IndestructibleWall object
     */
    ~IndestructibleWall();

    /**
     * @brief update the Indestructible wall (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual Indestructible wal
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite; ///< The actual Sprite
};

#endif // INDESTRUCTIBLEWALL_H
