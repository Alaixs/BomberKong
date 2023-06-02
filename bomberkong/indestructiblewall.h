#ifndef INDESTRUCTIBLEWALL_H
#define INDESTRUCTIBLEWALL_H

#include "entity.h"

class IndestructibleWall : public Entity
{
public:
    IndestructibleWall(int posX, int posY);
    IndestructibleWall(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    QPixmap sprite;
};

#endif // INDESTRUCTIBLEWALL_H
