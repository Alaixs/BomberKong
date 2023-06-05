#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include <QPainter>
#include "coordinate.h"


class GUIElement
{

protected:
    Coordinate pos;
    bool isSelected;

public:
    GUIElement(Coordinate position);
    GUIElement(int posX, int posY);

    Coordinate getPos();

    virtual void draw(QPainter * painter) = 0;
    virtual void select();
    virtual void deselect();

};

#endif // GUIELEMENT_H
