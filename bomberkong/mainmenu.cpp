#include "mainmenu.h"
#include "input.h"
#include "widget.h"
#include "global.h"
#include <list>


MainMenu::MainMenu(QWidget* widget)
    : Scene(widget)
{
    timer = 0;

    bg = new GUIElement(Coordinate(0, 0),
                            Coordinate(832, 832),
                            QString("://assets/sprites/t_menu_bg.png")
                        );
    gui.push_back(bg);

    logo = new GUIElement(Coordinate(100, 300),
                            Coordinate(440, 210),
                            QString("://assets/sprites/t_logo.png")
                          );
    gui.push_back(logo);

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
        pressStart->isVisible = !(pressStart->isVisible);
    }

    logo->setPos(Coordinate(logo->getPos().x, sin(0.06 * timer)*50 + 300));


    if (Input::isActionJustPressed(START))
    {
        dynamic_cast<Widget*>(root)->switchScene(1);
    }
}

void MainMenu::draw(QPainter *painter)
{
    painter->fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 0, 0)));

    int width = cellSize;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                width*2*i, width*2*j, width, width,
                QBrush(QColor(0, 161, 30))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j+cellSize, width, width,
                QBrush(QColor(0, 161, 30))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j, width, width,
                QBrush(QColor(1, 133, 21))
                );

            painter->fillRect(
                width*2*i, width*2*j+cellSize, width, width,
                QBrush(QColor(1, 133, 21))
                );
        }
    }

    std::list<GUIElement*>::iterator it;
    for (it = gui.begin(); it != gui.end(); it++)
    {
        (*it)->draw(painter);
    }
}
