#ifndef BARREL_H
#define BARREL_H
#include "animationmanager.h"
#include "entity.h"

class Barrel : public Entity
{
public:
    Barrel(int posX,int posY);
    Barrel(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    int timer = 187;
    QPixmap sprite;
    AnimationManager animation;
};

#endif // BARREL_H
