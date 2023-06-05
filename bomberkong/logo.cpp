#include "logo.h"

Logo::Logo(Coordinate position)
    : GUIElement(position)
{
    texture.load("://assets/sprites/t_logo.png");
}


void Logo::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 483, 212),
        texture
    );
}
