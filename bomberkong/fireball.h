#ifndef FIREBALL_H
#define FIREBALL_H
#include "entity.h"

class FireBall : public Entity
{
private:
    int timer;
    QPixmap sprite;
    AnimationManager * animation;

    int endY;
    bool isFlying;

public:
    FireBall(int posX, int posY, int endYPos);

    FireBall(Coordinate pos, int endYPos);

    ~FireBall();

    void update();

    void draw(QPainter * painter);

    QRect getRect();

    bool getIsFlying();
};

#endif // FIREBALL_H
