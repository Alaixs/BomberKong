#ifndef LOOSE_H
#define LOOSE_H

#include "donkeykong.h"
#include "guielement.h"
#include "scene.h"

class Loose : public Scene
{
public:
    Loose(QWidget* widget);

    void update();
    void draw(QPainter* painter);

    DonkeyKong* dk;
    GUIElement* go;
};

#endif // LOOSE_H
