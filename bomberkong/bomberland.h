#ifndef BOMBERLAND_H
#define BOMBERLAND_H
#include "level.h"
#include "reloaded.h"

class BomberLand : public Reloaded
{
public:
    BomberLand(QWidget* widget);
    ~BomberLand();

    void win();
};

#endif // BOMBERLAND_H
