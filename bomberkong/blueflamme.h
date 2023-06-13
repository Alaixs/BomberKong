#ifndef BLUEFLAMME_H
#define BLUEFLAMME_H
#include "enemy.h"
#include "playercharacter.h"
#include "explosion.h"
#include "wall.h"
#include "indestructiblewall.h"

class BlueFlamme : public Enemy
{
private:
    int timer ;                  ///< The number of frame the barrel will stay
    int direction;               ///< The direction selected
    int yDirection;
    int isOnBoard;               ///< If the flame is on the board 2, if fall 0, if just stopped 1
    bool flipped;                ///< If flipped skin
    Coordinate spawnCoordinate;  ///< The spawn coordinate of Flame
    QPixmap sprite;              ///< The actual Sprite
    AnimationManager* animation; ///< The actual animation ( the range in the sprite image)

public:
    BlueFlamme(int posX, int posY);
    BlueFlamme(Coordinate position, int DKY);
    ~BlueFlamme();

    void update() override;
    void draw(QPainter* painter) override;
    QRect getRect() override;
    void collisionEvent(Entity* body) override;
};

#endif // BLUEFLAMME_H
