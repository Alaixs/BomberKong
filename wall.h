#ifndef WALL_H
#define WALL_H


#include <QPainter>

#include "entity.h"


class Wall : public Entity
{

private:
    int itsX;
    int itsY;

public:
    Wall(int X, int Y);

    void update();
    void draw(QPainter * aPainter);
    QRect getRect();

};

#endif // WALL_H
