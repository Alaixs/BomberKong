#ifndef GLAGLA_H
#define GLAGLA_H

#include "level.h"

class Glagla : public Level
{
public:
    Glagla(QWidget * widget);

    Glagla(QWidget * widget, PlayerCharacter * player);

    void restart();
    void win();
};

#endif // GLAGLA_H
