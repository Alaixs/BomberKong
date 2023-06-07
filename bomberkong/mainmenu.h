#ifndef MAINMENU_H
#define MAINMENU_H

#include "scene.h"
#include "guielement.h"
#include <list>

/**
 * @brief The class of Main Menu
 */
class MainMenu : public Scene
{

public:
    /**
     * @brief Create a MainMenu
     * @param widget : the widget of the mainmenu scene
     */
    MainMenu(QWidget* widget);

    /**
     * @brief Update the Main Menu
     */
    void update();

    /**
     * @brief Display the actual Main Menu
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);

private:
    int timer;
    std::list<GUIElement*> gui;

    GUIElement* logo;
    GUIElement* pressStart;

};

#endif // MAINMENU_H
