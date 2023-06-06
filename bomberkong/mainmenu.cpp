#include "mainmenu.h"
#include "input.h"
#include "widget.h"


MainMenu::MainMenu(QWidget* widget)
    : Scene(widget)
{
    gui.push_back(
        new GUIElement(Coordinate(0, 0),
                       Coordinate(832, 832),
                       QString("://assets/sprites/t_menu_bg.png")
        )
    );

    gui.push_back(
        new GUIElement(Coordinate(100, 300),
                       Coordinate(440, 210),
                       QString("://assets/sprites/t_logo.png")
        )
    );

    gui.push_back(
        new GUIElement(Coordinate(140, 620),
                       Coordinate(350, 30),
                       QString("://assets/sprites/t_press_start.png")
        )
    );
}


void MainMenu::update()
{
    if (Input::isActionPressed(MOVE_DOWN))
    {
        dynamic_cast<Widget*>(root)->switchScene(1);
    }
}


void MainMenu::draw(QPainter *painter)
{
    std::list<GUIElement*>::iterator it;
    for (it = gui.begin(); it != gui.end(); it++)
    {
        (*it)->draw(painter);
    }
}
