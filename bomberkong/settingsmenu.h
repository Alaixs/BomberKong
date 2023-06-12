#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <vector>
#include "scene.h"
#include "textlabel.h"


class SettingsMenu : public Scene
{

private:
    TextLabel* windowTitle;

    TextLabel* labelMoveUp;
    TextLabel* labelMoveDown;
    TextLabel* labelMoveLeft;
    TextLabel* labelMoveRight;
    TextLabel* labelPlaceBomb;
    TextLabel* labelPushBomb;
    TextLabel* labelStart;

    TextLabel* labelBack;

    std::vector<TextLabel*> options;

    int currentSelectedOption;
    bool waitingForInput;

    GUIElement * bg;

public:
    SettingsMenu(QWidget* root);

    void update();
    void draw(QPainter* painter);

};

#endif // SETTINGSMENU_H
