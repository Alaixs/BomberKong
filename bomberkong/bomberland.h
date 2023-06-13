#ifndef BOMBERLAND_H
#define BOMBERLAND_H
#include "level.h"
#include "reloaded.h"

class BomberLand : public Reloaded
{
public:
    /**
     * @brief Constructor for a BomberLand level
     * @param widget : The main widget
     */
    BomberLand(QWidget* widget);

    /**
     * @brief Destructor for a BomberLand level
     */
    ~BomberLand();

    /**
     * @brief Called when the player finish the level. Shows the save menu and get to the next level (Chocho)
     */
    void win();
};

#endif // BOMBERLAND_H
