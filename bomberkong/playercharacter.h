#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "entity.h"
#include "animationmanager.h"
#include "soundmanager.h"


class PlayerCharacter : public Entity
{

public:
    PlayerCharacter(int posX, int posY);
    PlayerCharacter(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    void collisionEvent(Entity * body);

    void footstepsSfx();
    void loseThemeSfx();
    void winThemeSfx();
    void stopAllSounds();
    SoundManager* soundManager;


    QRect getRect();

private:
    QPixmap sprite;
    Coordinate motion;
    AnimationManager animation;
    int speed = 4; ///< The number of pixels traveled each frame
    bool flipped;
    int timer=0;

};

#endif // PLAYERCHARACTER_H
