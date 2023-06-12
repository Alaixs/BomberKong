#ifndef BARREL_H
#define BARREL_H
#include "animationmanager.h"
#include "entity.h"
#include "level.h"


/**
 * @brief The barrel throen by donkey kong
 */
class Barrel : public Entity
{

private:
    int timer;
    QPixmap sprite;              ///< The actual Sprite
    QPixmap shadow;              ///< The shadow of Tonneaux for throwing
    AnimationManager* animation; ///< The actual animation ( the range in the sprite image)
    bool isFlying;
    int endY;
    int endX;

public:
    /**
     * @brief Create a Barrel
     *
     * @param posX : position on X axis
     * @param posY : position on Y axis
     */
    Barrel(int posX,int posY, int endYPos = 816);

    /**
     * @brief Create a Barrel
     *
     * @param posX : position on X axes
     * @param posY : position on Y axes
     */
    Barrel(Coordinate pos, int endYPos = 816);

    /**
     * @brief Destructor for the Barrel object
     */
    ~Barrel();

    /**
     * @brief Update the barrel (position, animation, etc.)
     */
    void update();

    /**
     * @brief Display the barrel
     *
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief Create the hitbox of the barrel
     *
     * @return the hitboxe
     */
    QRect getRect();

    /**
     * @brief getIsFlying
     * @return if the barrel flying
     */
    bool getIsFlying();

};

#endif // BARREL_H
