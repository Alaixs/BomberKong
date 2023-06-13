#ifndef BOMBERLAND_H
#define BOMBERLAND_H
#include "level.h"

class BomberLand : public Level
{
public:
    BomberLand(QWidget* widget);

    /**
     * @brief Create the level from a file
     */
    void restart();
};

#endif // BOMBERLAND_H
