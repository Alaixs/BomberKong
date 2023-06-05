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
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Wall(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    void collisionEvent(Entity * body);

    QRect getRect();

private:
    QPixmap sprite;

};

#endif // WALL_H
