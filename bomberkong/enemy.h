#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
public:
    /**
     * @brief Create a Ennemy
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Enemy(int posX, int posY);

    /**
     * @brief Create a Ennemy
     * @param pos : position coordinate
     */
    Enemy(Coordinate pos);

    /**
     * @brief Destructor for a Ennemy object
     */
    virtual ~Enemy();

    /**
     * @brief Update the ennemy (position, sprite, etc)
     */
    virtual void update() = 0;

    /**
     * @brief Display the actual ennemy
     * @param painter : the tools to display
     */
    virtual void draw(QPainter *painter) = 0;

    virtual void collisionEvent(Entity *body) = 0;

    /**
     * @brief Create the hitbox of the ennemy
     * @return the hitbox
     */
    virtual QRect getRect() = 0;
};

#endif // ENEMY_H
