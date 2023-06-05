#ifndef PRESSSTARTLABEL_H
#define PRESSSTARTLABEL_H

#include "guielement.h"


class PressStartLabel : public GUIElement
{

private:
    QPixmap texture;

public:
    PressStartLabel(Coordinate pos);
    void draw(QPainter * painter);

};

#endif // PRESSSTARTLABEL_H
