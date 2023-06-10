#ifndef POWERUP_H
#define POWERUP_H
#include "entity.h"

enum PowerUpType { SPEED, BOMB_NB, BOMB_RANGE, BOMB_TIME, ARMOR };

class PowerUp : public Entity
{

private:
    QPixmap sprite;             ///< The actual Sprite
    PowerUpType itsType;        ///< The type of the Power-Up

public:
    /**
     * @brief Create a PowerUp
     * @param posX : position on x axes
     * @param posY : position on y axes
     * @param type : The type of Power-Up
     */
    PowerUp(int posX, int posY, PowerUpType type);

    /**
     * @brief Create a PowerUp
     * @param posX : position on x axes
     * @param posY : position on y axes
     * @param type : The type of Power-Up
     */
    PowerUp(Coordinate pos, PowerUpType type);

    /**
     * @brief Destructor for a PowerUp object
     */
    ~PowerUp();

    /**
     * @brief Load the sprite of the Power-Up
     */
    void loadSprite();

    /**
     * @brief Getter for the Power-Up type
     * @return The Power-Up type
     */
    PowerUpType getItsType();

    /**
     * @brief Display the actual Power-Up sprite
     * @param painter : the tools to display
     */
    void draw(QPainter * painter);

    /**
     * @brief Remove the Power-Up from the screen if the player collect it
     */
    void collected();

};

#endif // POWERUP_H
