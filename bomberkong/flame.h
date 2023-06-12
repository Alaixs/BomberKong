#ifndef FLAME_H
#define FLAME_H
#include "enemy.h"


class Flame : public Enemy
{

private:
    int timer ;                  ///< The number of frame the barrel will stay
    QPixmap sprite;              ///< The actual Sprite
    AnimationManager* animation; ///< The actual animation ( the range in the sprite image)

public:
    Flame(int posX, int posY);
    Flame(Coordinate position);
    ~Flame();

    void update() override;
    void draw(QPainter *painter) override;
    QRect getRect() override;
};
#endif // FLAME_H
