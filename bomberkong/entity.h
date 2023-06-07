#ifndef ENTITY_H
#define ENTITY_H
#include "coordinate.h"
#include <QPainter>
#include "scene.h"


/**
 * @brief An entity present in the game world.
 *
 * An entity with a position, a sprite and an optional collision box.
 * Every entity in the main widget `entities` vector will be updated each
 * tick (i.e. it's `update` method will be called).
 * Entities HAVE to be spawned in the game world using `createEntity` method
 * of the `widget` class, otherwise, the `parent` property won't be correctly
 * set.
 */
class Entity
{

private:
    bool active; ///< Delete the entity if false

protected:
    Coordinate pos; ///< The coordinate of the entity
    Scene* parent; ///< The main widget, used to call method from it.

public:

    /**
     * @brief Construct a new Entity object
     * @param x : the x coordinate
     * @param y : the y coordinate
     */
    Entity(int x, int y);

    /**
     * @brief Construct a new Entity object
     * @param pos : location coordinates
     */
    Entity(Coordinate pos);

    /**
     * @brief Set the parent property to a pointer to the main widget
     * @param newParent : The main widget
     */
    void setParent(Scene* newParent);

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
     * @brief isAlive
     * @return if the entity is active
     */
    bool isActive();

    /**
     * @brief update the entity (move, change direction, etc.)
     */
    virtual void update() = 0;

    /**
     * @brief draw the entity on the screen
     * @param painter : the painter of the game
     */
    virtual void draw(QPainter* painter);

    /**
     * @brief collisionEvent
     * @param body : the entity that collide with the current entity
     */
    virtual void collisionEvent(Entity* body);

    /**
     * @brief getRect get the rectangle of the entity
     * @return QRect the rectangle of the entity
     */
    virtual QRect getRect();



};

#endif // ENTITY_H
