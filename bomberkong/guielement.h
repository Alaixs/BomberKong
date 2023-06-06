#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include <QPainter>
#include "coordinate.h"


class GUIElement
{

protected:
    Coordinate pos;
    Coordinate size;
    QPixmap texture;
    bool isSelected;

public:
    GUIElement(Coordinate position, Coordinate newSize, QString source);
    GUIElement(int posX, int posY);

    Coordinate getPos();

    virtual void draw(QPainter * painter);
    virtual void select();
    virtual void deselect();

};

#endif // GUIELEMENT_H
