#ifndef FLAME_H
#define FLAME_H
#include "enemy.h"
#include "wall.h"
#include "indestructiblewall.h"


class Flame : public Enemy
{

private:
    int timer ;                  ///< The number of frame the barrel will stay
    int direction;               ///< The direction selected
    int isOnBoard;              ///< If the flame is on the board 2, if fall 0, if just stopped 1
    QPixmap sprite;              ///< The actual Sprite
    AnimationManager* animation; ///< The actual animation ( the range in the sprite image)

public:
    Flame(int posX, int posY);
    Flame(Coordinate position);
    ~Flame();

    void update() override;
    void draw(QPainter* painter) override;
    QRect getRect() override;
    void collisionEvent(Entity* body) override;
};
#endif // FLAME_H
