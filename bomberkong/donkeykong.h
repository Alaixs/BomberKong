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

    /**
     * @brief update the Donkey Kong (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual DK
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();

private:
    QPixmap sprite;///< The actual Sprite
    int timer;///< init timer
    AnimationManager animation;///< The actual animation

    int newPos; ///< Pose where the DK send the next barrel
    int dist;   ///< Distance to the next x where DK send barrel
};

#endif // DONKEYKONG_H
