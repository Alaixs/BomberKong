#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include <QPainter>
#include "coordinate.h"


/**
 * @brief The GUIElement class, elements of GUI you will see on menu
 */
class GUIElement
{

protected:
    Coordinate pos;
    Coordinate size;
    bool isSelected;

public:
    QPixmap texture;
    bool isVisible;

    /**
     * @brief Create a GUI element
     * @param position : the coordinate of position on screen
     * @param newSize : the size of element
     * @param source : the path to the file
     */
    GUIElement(Coordinate position, Coordinate newSize, QString source);

    /**
     * @brief Create a GUI element
     * @param posX : the x value
     * @param posY : the y value
     */
    GUIElement(int posX, int posY);

    /**
     * @brief Virtual destructor for GUI elements
     */
    virtual ~GUIElement();

    /**
     * @brief Returns the position of the element
     * @return the position as a Coordinate
     */
    Coordinate getPos();

    /**
     * @brief Sets the position of the element.
     * @param position : the new position of the element
     */
    void setPos(Coordinate position);

    /**
     * @brief Displays the element
     * @param painter The QPainter class
     */
    virtual void draw(QPainter * painter);

    /**
     * @brief Select the element
     */
    virtual void select();

    /**
     * @brief Unselect the element
     */
    virtual void deselect();

    /**
     * @brief Function to know if the element is currently selected
     * @return The isSelected boolean
     */
    bool isElementSelected();

    /**
     * @brief Move the element on the screen
     * @param trX : the x value to move
     * @param trY : the y value to move
     */
    void move(int trX, int trY);

    /**
     * @brief Move the element on the screen
     * @param translation : the coordinate to move
     */
    void move(Coordinate translation);

};

#endif // GUIELEMENT_H
