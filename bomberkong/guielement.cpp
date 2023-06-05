#include "guielement.h"


GUIElement::GUIElement(Coordinate position)
{
    pos = position;
    isSelected = false;
}


GUIElement::GUIElement(int posX, int posY)
{
    pos.x = posX;
    pos.y = posY;
    isSelected = false;
}


Coordinate GUIElement::getPos()
{
    return pos;
}


void GUIElement::select()
{
    isSelected = true;
}


void GUIElement::deselect()
{
    isSelected = false;
}


void GUIElement::draw(QPainter * painter)
{

}
