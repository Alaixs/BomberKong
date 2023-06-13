#include "bomberland.h"
#include "hammer.h"

BomberLand::BomberLand(QWidget* widget)
    : Reloaded(widget)
{
    itsSceneType = BOMBERLAND;
}

BomberLand::~BomberLand()
{

}

void BomberLand::win()
{
    dynamic_cast<Widget*>(root)->saveGame(0, itsPlayer);
}
