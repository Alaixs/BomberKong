#ifndef ICEBLOC_H
#define ICEBLOC_H
#include "entity.h"

class IceBloc : public Entity
{
private:
    int timer;
    QPixmap sprite;
    AnimationManager * animation;

    int endY;
    bool isFlying;

public:
    IceBloc(int posX, int posY, int endYPos);

    IceBloc(Coordinate pos, int endYPos);

    ~IceBloc();

    void update();

    void draw(QPainter * painter);

    QRect getRect();

    bool getIsFlying();
};

#endif // ICEBLOC_H
