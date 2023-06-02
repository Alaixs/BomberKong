#ifndef BOMBERGIRL_H
#define BOMBERGIRL_H

#include "entity.h"

class BomberGirl : public Entity
{
public:
    BomberGirl(int posX, int posY);
    BomberGirl(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    void collisionEvent(Entity * body);

    QRect getRect();

private:
    QPixmap sprite;
};

#endif // BOMBERGIRL_H
