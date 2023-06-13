#ifndef CHOCHO_H
#define CHOCHO_H
#include "level.h"

class Chocho : public Level
{
public:
    Chocho(QWidget * widget);

    void restart();
};



#endif // CHOCHO_H
