#ifndef LOGO_H
#define LOGO_H

#include "guielement.h"


class Logo : public GUIElement
{

private:
    QPixmap texture;

public:
    Logo(Coordinate pos);
    void draw(QPainter * painter);

};

#endif // LOGO_H
