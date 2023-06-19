#ifndef GLAGLA_H
#define GLAGLA_H

#include "level.h"

class Glagla : public Level
{
public:
    /**
     * @brief Constructor for a Glagla level
     * @param widget : The main widget
     */
    Glagla(QWidget * widget);

    /**
     * @brief Constructor for a Glagla level
     * @param widget : The main widget
     * @param player : The player
     */
    Glagla(QWidget * widget, PlayerCharacter * player);

    /**
     * @brief Create the level from a file
     */
    void restart();

    /**
     * @brief Called when the player finish the level. Shows the save menu and get to the next level (Jungle DK)
     */
    void win();
};

#endif // GLAGLA_H
