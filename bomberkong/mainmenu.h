#ifndef MAINMENU_H
#define MAINMENU_H

#include <list>
#include "scene.h"
#include "guielement.h"
#include "textlabel.h"


/**
 * @brief The class of Main Menu
 */
class MainMenu : public Scene
{

private:
    int timer;                      ///< Timer for the blinking "press start" label
    bool saveFileFound;             ///< Bool to know if a save file was found
    std::list<GUIElement*> gui;     ///< A list of GUI Elements
    GUIElement * bg;                ///< The actual Sprite
    GUIElement * logo;              ///< The actual Sprite
    GUIElement * pressStart;        ///< The press start GUI
    GUIElement * options;           ///< The options cogwheel
    TextLabel * choiceTutorial;     ///< The TUTORIAL level label
    TextLabel * choiceOriginal;     ///< The ORIGINAL level label
    TextLabel * choiceReloaded;     ///< The RELOADED level label
    TextLabel * choiceJourney;      ///< The JOURNEY level label
    TextLabel * choiceLoad;         ///< The LOAD label
    GUIElement * selected;          ///< The currently selected label

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

    /**
     * @brief Plays sfx select sound
     */
    void selectSfx();

};

#endif // MAINMENU_H
