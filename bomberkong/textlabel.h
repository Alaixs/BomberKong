#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "guielement.h"


enum Alignement
{
    LEFT,
    CENTER,
    RIGHT
};

class TextLabel : public GUIElement
{

private:
    QString labelText;
    QFont font;
    Alignement textAlign; // LEFT, CENTER or RIGHT
    int fontSize;
    QBrush textColor;

public:
    /**
     * @brief The constructor for the TextLabell object
     *
     * @param x : The position on the X axis
     * @param y : The position on the Y axis
     * @param size : The font size (in pixels)
     * @param t : The text
     */
    TextLabel(int x, int y, int size, QString text, Alignement align = LEFT);

    /**
     * @brief Draws the label on the screen
     *
     * @param painter : The QPainter object used to draw the label
     */
    void draw(QPainter* painter);

    /**
     * @brief Changes the text displayed by the label
     *
     * @param text : The text to display
     */
    void setText(QString text);

    /**
     * @brief Changes the color of the label
     *
     * @param color : The new color
     */
    void setColor(QBrush color);

};

#endif // TEXTLABEL_H
