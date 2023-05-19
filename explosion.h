#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "entity.h"


class Explosion : public Entity
{

public:
    Explosion(int X, int Y);
    void update();
    void draw(QPainter * aPainter);
    void playSound();
    QRect getRect();

private:
    int timer = 13;

};

#endif // EXPLOSION_H
