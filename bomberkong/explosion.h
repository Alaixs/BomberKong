#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "animationmanager.h"
#include "entity.h"

class Explosion : public Entity
{

public:
    Explosion(int posX, int posY);
    Explosion(Coordinate position);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    QPixmap sprite;
    AnimationManager animation;
    int timer = 12;

};

#endif // EXPLOSION_H
