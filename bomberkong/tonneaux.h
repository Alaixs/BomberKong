#ifndef TONNEAUX_H
#define TONNEAUX_H
#include "animationmanager.h"
#include "entity.h"

class Tonneaux : public Entity
{
public:
    Tonneaux(int posX,int posY);
    Tonneaux(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    int timer = 187;
    QPixmap sprite;
    AnimationManager animation;
};

#endif // TONNEAUX_H
