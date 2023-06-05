#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"
#include "animationmanager.h"
#include "soundmanager.h"

class Character : public Entity
{
public:
    Character(int posX, int posY);
    Character(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    void loseThemeSfx();
    void stopAllSounds();
    SoundManager* soundManager;


    QRect getRect();

private:
    QPixmap sprite;
    Coordinate motion;
    AnimationManager animation;
    int timer=0;
};

#endif // CHARACTER_H
