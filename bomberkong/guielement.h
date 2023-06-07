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
    bool isVisible;

    GUIElement(Coordinate position, Coordinate newSize, QString source);
    GUIElement(int posX, int posY);

    /**
     * @brief Returns the position of the element
     * @return the position as a Coordinate
     */
    Coordinate getPos();

    /**
     * @brief Displays the element
     * @param painter The QPainter class
     */
    virtual void draw(QPainter * painter);
    virtual void select();
    virtual void deselect();

    void move(int trX, int trY);
    void move(Coordinate translation);

};

#endif // GUIELEMENT_H
