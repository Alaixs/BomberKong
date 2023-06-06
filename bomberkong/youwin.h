#ifndef YOUWIN_H
#define YOUWIN_H

#include "guielement.h"


class YouWin : public GUIElement
{

private:
    QPixmap texture;

public:
    YouWin(Coordinate pos);
    void draw(QPainter * painter);

};
#endif // YOUWIN_H
