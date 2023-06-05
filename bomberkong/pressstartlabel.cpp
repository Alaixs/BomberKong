#include "pressstartlabel.h"
#include "input.h"

PressStartLabel::PressStartLabel(Coordinate position)
    : GUIElement(position)
{
    texture.load("://assets/sprites/t_press_start.png");
}


void PressStartLabel::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 360, 34),
        texture
    );
}
