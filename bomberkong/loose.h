#ifndef LOOSE_H
#define LOOSE_H

#include "donkeykong.h"
#include "guielement.h"
#include "scene.h"

/**
 * @brief The class of loose screen
 */
class Loose : public Scene
{
public:
    /**
     * @brief Create a Loose screen
     * @param widget : the widget of loose scene
     */
    Loose(QWidget* widget);


    /**
     * @brief Update the Loose screen
     */
    void update();

    /**
     * @brief Display the actual Loose screen
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);

    DonkeyKong * dk;
    GUIElement * go;
};

#endif // LOOSE_H
