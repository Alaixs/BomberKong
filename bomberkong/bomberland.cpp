#include "bomberland.h"
#include "hammer.h"

BomberLand::BomberLand(QWidget* widget)
    : Reloaded(widget)
{
    itsSceneType = BOMBERLAND;

    setOffsetLimit(352, -864);
}

BomberLand::~BomberLand()
{

}

void BomberLand::win()
{
    // Open the save menu and go to the next level (Chocho)
    dynamic_cast<Widget*>(root)->saveGame(0, itsPlayer);
}
