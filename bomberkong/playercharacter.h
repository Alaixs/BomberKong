#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "entity.h"
#include "animationmanager.h"

class PlayerCharacter : public Entity
{

public:
    PlayerCharacter(int posX, int posY);
    PlayerCharacter(Coordinate pos);

    void update();
    void draw(QPainter * painter);

private:
    QPixmap sprite;
    Coordinate motion;
    AnimationManager animation;
    int speed = 4; ///< The number of pixels traveled each frame

};

#endif // PLAYERCHARACTER_H
