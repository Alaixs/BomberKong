#ifndef HAMMER_H
#define HAMMER_H

#include "entity.h"

class Hammer : public Entity
{
private:
    QPixmap sprite;              ///< The actual Sprite
    AnimationManager* animation; ///< The actual animation ( the range in the sprite image)

public:
    /**
     * @brief Create a Hammer
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Hammer(int posX, int posY);

    /**
     * @brief Create a Hammer
     * @param posX : position on x axes
     * @param posY : position on y axes
     */
    Hammer(Coordinate pos);

    /**
     * @brief Destructor for a Hammer object
     */
    ~Hammer();

    /**
     * @brief update Hammer (position, sprite, etc)
     */
    void update();

    /**
     * @brief Display the actual Hammer's sprite
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief create the hitboxe
     * @return the hitboxe
     */
    QRect getRect();
};

#endif // HAMMER_H
