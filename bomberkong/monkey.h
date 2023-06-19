#ifndef MONKEY_H
#define MONKEY_H

#include "entity.h"


class Monkey : public Entity
{

private:
    QPixmap sprite;
    QPixmap lianaSprite;
    AnimationManager* animation;
    Coordinate motion;
    Coordinate targetPosition;
    bool isOnGround;
    int timer;

public:
    Monkey(Coordinate dropPosition, QString spriteSource);
    ~Monkey();

    void update() override;
    void draw(QPainter* painter) override;

    QRect getRect() override;

};

#endif // MONKEY_H
