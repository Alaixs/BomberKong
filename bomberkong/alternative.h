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
    /**
     * @brief Create the alternative ending scene
     * @param widget : the main  widget
     */
    Alternative(QWidget* widget);

    /**
     * @brief Update th ealternative ending scene
     */
    void update();

    /**
     * @brief Display the actual barrel
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);
};

#endif // ALTERNATIVE_H
