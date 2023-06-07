#ifndef WIN_H
#define WIN_H

#include "bombergirl.h"
#include "dummy.h"
#include "guielement.h"
#include "scene.h"

class Win : public Scene
{
public:
    Win(QWidget * widget);

    void update();
    void draw(QPainter * painter);

    Dummy * bomberman;
    BomberGirl * bombergirl;
    GUIElement * winLabel;
};

#endif // WIN_H
