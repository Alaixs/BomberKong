#ifndef ORIGINAL_H
#define ORIGINAL_H
#include "level.h"

class Original : public Level
{
public:
    Original(QWidget* widget);

    /**
     * @brief Creates the level from a file
     */
    void restart();
};

#endif // ORIGINAL_H
