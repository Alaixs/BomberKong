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
    pressStart = new TextLabel(320, 750, 50, "PRESS SPACE", CENTER);
    gui.push_back(pressStart);

    // Options
    options = new GUIElement(Coordinate(575, 765),
                          Coordinate(32, 32),
                          QString("://assets/sprites/t_options.png")
                          );
    gui.push_back(options);

    // Tutorial level option
    choiceTutorial = new TextLabel(320, 440, 50, "TUTORIAL", CENTER);
    gui.push_back(choiceTutorial);

    // Original level option
    choiceOriginal = new TextLabel(320, 540, 50, "ORIGINAL", CENTER);
    gui.push_back(choiceOriginal);

    // Reloaded level option
    choiceReloaded = new TextLabel(320, 640, 50, "RELOADED", CENTER);
    gui.push_back(choiceReloaded);

    selected = new GUIElement(Coordinate(140, 405),
                              Coordinate(48, 48),
                              QString("://assets/sprites/selected_menu.png"));
    gui.push_back(selected);

    choiceTutorial->select(); // Choose the tutorial level by default
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



    if (timer % 40 == 0)
    {
        // Blinking "press start" label
        pressStart->isVisible = !(pressStart->isVisible);
    }

    logo->setPos(Coordinate(logo->getPos().x, sin(0.06 * timer)*60 + 80)); // Animate the logo

    if (Input::isActionJustPressed(MOVE_DOWN))
    {
        selectSfx();
        if (choiceTutorial->isElementSelected())
        {
            choiceTutorial->deselect();
            choiceOriginal->select();
            selected->setPos(Coordinate(120,505));
        }
        else if (choiceOriginal->isElementSelected())
        {
            choiceOriginal->deselect();
            choiceReloaded->select();
            selected->setPos(Coordinate(120,605));
        }
        else if (choiceReloaded->isElementSelected())
        {
            choiceReloaded->deselect();
            choiceTutorial->select();
            selected->setPos(Coordinate(120,405));
        }
    }

    if (Input::isActionJustPressed(MOVE_UP))
    {
        selectSfx();
        if (choiceTutorial->isElementSelected())
        {
            choiceTutorial->deselect();
            choiceReloaded->select();
            selected->setPos(Coordinate(120,605));
        }
        else if (choiceOriginal->isElementSelected())
        {
            choiceOriginal->deselect();
            choiceTutorial->select();
            selected->setPos(Coordinate(120,405));
        }
        else if (choiceReloaded->isElementSelected())
        {
            choiceReloaded->deselect();
            choiceOriginal->select();
            selected->setPos(Coordinate(120,505));
        }
    }

    if (Input::isActionJustPressed(START)) // The player pressed space to start the game
    {
        if (choiceTutorial->isElementSelected()) // Start the tutorial level
            dynamic_cast<Widget*>(root)->switchScene(TUTORIAL);
        else if (choiceOriginal->isElementSelected()) // Start the Original level
            dynamic_cast<Widget*>(root)->switchScene(ORIGINAL);
        else if (choiceReloaded->isElementSelected()) // Start the Reloaded level
            dynamic_cast<Widget*>(root)->switchScene(RELOADED);
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

void MainMenu::selectSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_select.wav", 1, false);
}
