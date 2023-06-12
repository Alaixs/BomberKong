#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <vector>
#include "scene.h"
#include "textlabel.h"


class SettingsMenu : public Scene
{

private:
    GUIElement * bg;

    TextLabel* windowTitle;

    TextLabel* labelMoveUp;
    TextLabel* labelMoveDown;
    TextLabel* labelMoveLeft;
    TextLabel* labelMoveRight;
    TextLabel* labelPlaceBomb;
    TextLabel* labelPushBomb;
    TextLabel* labelStart;

    TextLabel* labelReset;

    TextLabel* labelBack;

    std::vector<TextLabel*> options; ///< A list containing every selectable options

    int currentSelectedOption;       ///< The index of the currently selected option
    bool waitingForInput;            ///< Is the menu currently waiting for the user to choose an key


public:
    SettingsMenu(QWidget* root);

    /**
     * @brief Update the state of every updatable element in this menu
     */
    void update();

    /**
     * @brief Draw the menu
     * @param painter : The QPainter object used to draw the menu
     */
    void draw(QPainter* painter);

};

#endif // SETTINGSMENU_H
