#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
public:
    /**
     * @brief Construct a new Enemy
     * @param x : the x coordinate
     * @param y : the y coordinate
     */
    Enemy(int x, int y);

    /**
     * @brief Construct a new Enemy object
     * @param pos : location coordinates
     */
    Enemy(Coordinate pos);
};

#endif // ENEMY_H
