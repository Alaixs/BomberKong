#include "mainmenu.h"

#include <list>
#include <cmath>
#include "input.h"
#include "widget.h"
#include "global.h"


MainMenu::MainMenu(QWidget* widget)
    : Scene(widget)
{
    timer = 0;

    // Background
    bg = new GUIElement(Coordinate(0, 0),
                            Coordinate(832, 832),
                            QString("://assets/sprites/t_menu_bg.png")
                        );
    gui.push_back(bg);

    // Logo
    logo = new GUIElement(Coordinate(100, 300),
                            Coordinate(440, 210),
                            QString("://assets/sprites/t_logo.png")
                          );
    gui.push_back(logo);

    // "Press Start" Label
    pressStart = new GUIElement(Coordinate(140, 620),
                                    Coordinate(350, 30),
                                    QString("://assets/sprites/t_press_start.png")
                                );
    gui.push_back(pressStart);
}

MainMenu::~MainMenu()
{
    for (std::list<GUIElement*>::iterator it = gui.begin();
         it != gui.end(); it++) // Loop to delete every elements inside the gui list
    {
        delete (*it); // Delete the current element of the list
    }
    gui.clear();
}


void MainMenu::update()
{
    timer++;

    if (timer %  40 == 0)
    {
        // Blinking "press start" label
        pressStart->isVisible = !(pressStart->isVisible);
    }

    logo->setPos(Coordinate(logo->getPos().x, sin(0.06 * timer)*60 + 80));

    // Start the tutorial
    if (Input::isActionJustPressed(START))
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
