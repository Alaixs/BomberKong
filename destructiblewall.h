#ifndef DESTRUCTIBLEWALL_H
#define DESTRUCTIBLEWALL_H


#include <QPainter>

#include "entity.h"
\

class DestructibleWall : public Entity
{

public:
    DestructibleWall(int X, int Y);
    void collisionEvent(Entity * body);
    void update();
    void draw(QPainter * aPainter);
    QRect getRect();

};

#endif // DESTRUCTIBLEWALL_H
