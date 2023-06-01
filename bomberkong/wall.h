#ifndef WALL_H
#define WALL_H

#include "entity.h"


class Wall : public Entity
{

public:
    Wall(int posX, int posY);
    Wall(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    QPixmap sprite;

};

#endif // WALL_H
