#ifndef BANANA_H
#define BANANA_H

#include "entity.h"


class Banana : public Entity
{

private:
    QPixmap sprite;
    Coordinate targetPos;
    Coordinate motion;
    bool isOnGround;

public:
    Banana(Coordinate position, Coordinate targetPosition);
    Banana(int posX, int posY, Coordinate targetPosition);

    void update() override;
    void draw(QPainter* painter) override;

    QRect getRect();
    void collisionEvent(Entity* body);

};


#endif // BANANA_H
