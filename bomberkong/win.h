#ifndef WIN_H
#define WIN_H

#include "bombergirl.h"
#include "dummy.h"
#include "guielement.h"
#include "scene.h"

/**
 * @brief The class of the win screen
 */
class Win : public Scene
{
    Dummy * bomberman;
    BomberGirl * bombergirl;
    GUIElement * winLabel;

public:
    /**
     * @brief Create a new win screen
     * @param widget : the main widget
     */
    Win(QWidget * widget);

    /**
     * @brief Destructor for a Win object
     */
    ~Win();

    /**
     * @brief Update the Loose screen
     */
    void update();

    /**
     * @brief Display the actual Loose screen
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);
};

#endif // WIN_H
