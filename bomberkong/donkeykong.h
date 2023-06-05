#ifndef DONKEYKONG_H
#define DONKEYKONG_H
#include "entity.h"
#include "animationmanager.h"

class DonkeyKong : public Entity
{
public:
    /**
     * @brief Create a DK
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    DonkeyKong(int posX, int posY);

    /**
     * @brief Create a DK
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    DonkeyKong(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    QPixmap sprite;
    int timer=0;
    AnimationManager animation;

    int newPos;
    int dist;
};

#endif // DONKEYKONG_H
