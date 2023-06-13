#include "guielement.h"


GUIElement::GUIElement(int posX, int posY)
{
    pos.x = posX;
    pos.y = posY;

    isSelected = false;
    isVisible = true;
}

GUIElement::GUIElement(Coordinate position, Coordinate newSize, QString source)
{
    pos = position;
    size = newSize;

    // Loads the texture from a path
    texture.load(source);

    isSelected = false;
    isVisible = true;
}


GUIElement::GUIElement(int posX, int posY, Coordinate newSize, QString source)
{
    pos.x = posX;
    pos.y = posY;

    size = newSize;

    // Loads the texture from a path
    texture.load(source);

    isSelected = false;
    isVisible = true;
}


GUIElement::~GUIElement()
{

}


Coordinate GUIElement::getPos()
{
    return pos;
}


void GUIElement::setPos(Coordinate position)
{
    pos = position;
}


void GUIElement::select()
{
    isSelected = true;
}


void GUIElement::deselect()
{
    isSelected = false;
}


bool GUIElement::isElementSelected()
{
    return isSelected;
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
    // Translates the element
    pos.x += trX;
    pos.y += trY;
}


void GUIElement::move(Coordinate translation)
{
    // Translates the element
    pos += translation;
}
