#ifndef RELOADED_H
#define RELOADED_H
#include "level.h"

class Reloaded : public Level
{
public:
    Reloaded(QWidget* widget);

    void restart();
};

#endif // RELOADED_H
