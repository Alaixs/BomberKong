#ifndef BOMB_H
#define BOMB_H

#include "entity.h"
#include "animationmanager.h"

class Bomb : public Entity
{

public:
    Bomb(int posX, int posY);
    Bomb(Coordinate position);

    void update();
    void draw(QPainter * painter);
    void collisionEvent(Entity * body);

    QRect getRect();

private:
    int timer = 187;
    QPixmap sprite;
    AnimationManager animation;

};

#endif // BOMB_H
