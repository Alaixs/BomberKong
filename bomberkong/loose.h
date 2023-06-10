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
    DonkeyKong* dk;
    GUIElement* go;

    /**
     * @brief Create a Loose screen
     * @param widget : the widget of loose scene
     */
    Loose(QWidget* widget);

    /**
     * @brief Destructor for a Loose object
     */
    ~Loose();

    /**
     * @brief Update the Loose screen
     */
    void update();

    /**
     * @brief Display the actual Loose screen
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);

    /**
     * @brief Stop the main theme music and change for the loose sound
     */
    void changeSound();

};

#endif // LOOSE_H
