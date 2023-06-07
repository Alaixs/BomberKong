#ifndef ALTERNATIVE_H
#define ALTERNATIVE_H

#include "dummy.h"
#include "guielement.h"
#include "scene.h"

class Alternative : public Scene
{
public:
    Alternative(QWidget * widget);

    void update();
    void draw(QPainter * painter);

    Dummy * bomberman;

    std::list<GUIElement*> gui;
};

#endif // ALTERNATIVE_H
