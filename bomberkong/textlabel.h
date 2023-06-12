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
    QString text;
    QFont font;
    Alignement textAlign;
    int fontSize;

public:
    /**
     * @brief The constructor for the TextLabell object
     *
     * @param x : The position on the X axis
     * @param y : The position on the Y axis
     * @param size : The font size (in pixels)
     * @param t : The text
     */
    TextLabel(int x, int y, int size, QString t, Alignement alignement = LEFT);
    void draw(QPainter* painter);

};

#endif // TEXTLABEL_H
