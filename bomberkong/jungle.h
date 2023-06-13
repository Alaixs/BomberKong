#ifndef JUNGLE_H
#define JUNGLE_H

#include "level.h"


class Jungle : public Level
{

public:
    Jungle(QWidget* widget);

    /**
     * @brief Create the level from a file
     */
    void restart() override;

};

#endif // JUNGLE_H
