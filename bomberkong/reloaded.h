#ifndef RELOADED_H
#define RELOADED_H
#include "level.h"

class Reloaded : public Level
{
public:
    Reloaded(QWidget* widget);

    /**
     * @brief Create the level from a file
     */
    void restart();
};

#endif // RELOADED_H
