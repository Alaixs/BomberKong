#ifndef JUNGLE_H
#define JUNGLE_H

#include "level.h"


class Jungle : public Level
{

public:
    /**
     * @brief Constructor for a Jungle DK level
     * @param widget : The main widget
     */
    Jungle(QWidget* widget);

    /**
     * @brief Constructor for a Jungle DK level
     * @param widget : The main widget
     * @param player : The player
     */
    Jungle(QWidget * widget, PlayerCharacter * player);

    /**
     * @brief Create the level from a file
     */
    void restart() override;

};

#endif // JUNGLE_H
