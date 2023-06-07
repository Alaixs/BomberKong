#ifndef WIN_H
#define WIN_H

#include "bombergirl.h"
#include "demicharacter.h"
#include "guielement.h"
#include "scene.h"

class Win : public Scene
{
public:
    Win(QWidget * widget);
    ~Win();

    void update();
    void draw(QPainter * painter);

    Character * bomberman;
    BomberGirl * bombergirl;
    GUIElement * winLabel;
};

#endif // WIN_H
