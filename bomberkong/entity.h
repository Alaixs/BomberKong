#ifndef ENTITY_H
#define ENTITY_H
#include "coordinate.h"
#include <QPainter>


class Entity
{

    /**
    *
    *
    */

private:
    Coordinate pos;///< The coordinate of the entity
    bool isActive;///< Delete the entity

public:

    /**
     * @brief Construct a new Entity object
     * @param x the x coordinate
     * @param y the y coordinate
     */
    Entity(int x, int y);

    /**
     * @brief Construct a new Entity object
     * @param pos the coordinate of the entity
     */
    Entity(Coordinate pos);

    /**
     * @brief getter of the coordinate
     * @return Coordinate the coordinate of the entity
     */
    Coordinate getPos();

    /**
     * @brief delete the entity
     */
    void deleteEntity();

    /**
     * @brief update the entity (move, change direction, etc.)
     */
    virtual void update() = 0;

    /**
     * @brief draw the entity on the screen
     * @param painter the painter of the game
     */
    virtual void draw(QPainter * painter);

    /**
     * @brief collisionEvent
     * @param body the entity that collide with the current entity
     */
    virtual void collisionEvent(Entity* body);

    /**
     * @brief getRect get the rectangle of the entity
     * @return QRect the rectangle of the entity
     */
    virtual QRect getRect();



};

#endif // ENTITY_H
