#include "guielement.h"


GUIElement::GUIElement(Coordinate position, Coordinate newSize, QString source)
{
    pos = position;
    size = newSize;

    texture.load(source);

    isSelected = false;
    isVisible = true;
}


GUIElement::GUIElement(int posX, int posY)
{
    pos.x = posX;
    pos.y = posY;
    isSelected = false;
    isVisible = true;
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
    if (isVisible)
    {
        painter->drawPixmap(
            QRect(pos.x, pos.y, size.x, size.y),
            texture
        );
    }
}


void GUIElement::move(int trX, int trY)
{
    pos.x += trX;
    pos.y += trY;
}


void GUIElement::move(Coordinate translation)
{
    pos += translation;
}
