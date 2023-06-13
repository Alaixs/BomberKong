#ifndef MONKEY_H
#define MONKEY_H

#include "entity.h"


class Monkey : public Entity
{

private:
    QPixmap sprite;
    AnimationManager* animation;
    Coordinate motion;
    Coordinate targetPosition;

public:
    Monkey(Coordinate dropPosition, QString spriteSource);
    ~Monkey();

    void update() override;
    void draw(QPainter* painter) override;

    QRect getRect() override;

};

#endif // MONKEY_H
