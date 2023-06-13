#ifndef CHOCHO_H
#define CHOCHO_H
#include "level.h"

class Chocho : public Level
{
public:
    /**
     * @brief Constructor for a Chocho level
     * @param widget : The main widget
     */
    Chocho(QWidget * widget);

    /**
     * @brief Constructor for a Chocho level
     * @param widget : The main widget
     * @param player : The player
     */
    Chocho(QWidget * widget, PlayerCharacter * player);

    /**
     * @brief Create the level from a file
     */
    void restart();

    /**
     * @brief Called when the player finish the level. Shows the save menu and get to the next level (Glagla)
     */
    void win();
};



#endif // CHOCHO_H
