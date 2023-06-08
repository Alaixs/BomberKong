#ifndef ALTERNATIVE_H
#define ALTERNATIVE_H

#include "guielement.h"
#include "dummy.h"
#include "scene.h"


/**
 * @brief The alternative ending scene
 */
class Alternative : public Scene
{

private:
    Dummy* bomberman;
    std::list<GUIElement*> gui; ///< A list containing every GUI element

public:
    Alternative(QWidget* widget);

    void update();
    void draw(QPainter* painter);
};

#endif // ALTERNATIVE_H
