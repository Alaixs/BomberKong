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

private:
    int timer;
    std::list<GUIElement*> gui;

    GUIElement * bg; ///< The actual Sprite
    GUIElement * logo; ///< The actual Sprite
    GUIElement * pressStart; ///< The press start GUI
    GUIElement * options; ///< The options cogwheel
    GUIElement * choiceTutorial; ///< The actual Sprite
    GUIElement * choiceOriginal; ///< The actual Sprite
    GUIElement * choiceReloaded; ///< The actual Sprite

public:
    /**
     * @brief Create a MainMenu
     * @param widget : the widget of the mainmenu scene
     */
    MainMenu(QWidget* widget);

    /**
     * @brief Destructor for a MainMenu object
     */
    ~MainMenu();

    /**
     * @brief Update the Main Menu
     */
    void update();

    /**
     * @brief Display the actual Main Menu
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);

};

#endif // MAINMENU_H
