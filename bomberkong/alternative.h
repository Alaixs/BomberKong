#ifndef ALTERNATIVE_H
#define ALTERNATIVE_H

#include "dummy.h"
#include "guielement.h"
#include "scene.h"

/**
 * @brief The alternative ending scene
 */
class Alternative : public Scene
{
    Dummy * bomberman;
    std::list<GUIElement*> gui;

public:
    Alternative(QWidget * widget);

    void update();
    void draw(QPainter * painter);
};

#endif // ALTERNATIVE_H
