#ifndef BARREL_H
#define BARREL_H
#include "animationmanager.h"
#include "entity.h"


/**
 * @brief The class of barrel throw by Donkey Kong
 */
class Barrel : public Entity
{

private:
    int timer ;                  ///< The number of frame the barrel will stay
    QPixmap sprite;              ///< The actual Sprite
    AnimationManager* animation; ///< The actual animation ( the range in the sprite image)

public:
    /**
     * @brief Create a Barrel
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Barrel(int posX,int posY);

    /**
     * @brief Create a Barrel
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Barrel(Coordinate pos);

    /**
     * @brief Destructor for a Barrel object
     */
    ~Barrel();

    /**
     * @brief update the barrel (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual barrel
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief create the hitboxe of the barrel
     * @return the hitboxe
     */
    QRect getRect();

};

#endif // BARREL_H
