#include "guielement.h"


GUIElement::GUIElement(Coordinate position, Coordinate newSize, QString source)
{
    pos = position;
    size = newSize;

    texture.load(source);

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
    painter->drawPixmap(
        QRect(pos.x, pos.y, size.x, size.y),
        texture
    );
}
