#ifndef MAINMENU_H
#define MAINMENU_H

#include "scene.h"
#include "guielement.h"
#include <list>


class MainMenu : public Scene
{

public:
    MainMenu(QWidget* widget);
    ~MainMenu();
    void update();
    void draw(QPainter* painter);


private:
    int timer;
    std::list<GUIElement*> gui;

    GUIElement* logo;
    GUIElement* pressStart;

};

#endif // MAINMENU_H
