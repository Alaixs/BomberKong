#include "youwin.h"

YouWin::YouWin(Coordinate position)
    : GUIElement(position)
{
    texture.load("://assets/sprites/you_win.png");
}


void YouWin::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 483, 212),
        texture
        );
}
