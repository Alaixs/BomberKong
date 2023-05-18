#ifndef BOMB_H
#define BOMB_H

#include "entity.h"


class Bomb : public Entity
{

public:
    Bomb(int X = 0, int Y = 0);

    void detonate();

    void update();
    void draw(QPainter * aPainter);

private:
    int timer = 187;

};

#endif // BOMB_H
