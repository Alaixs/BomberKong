#include "alternative.h"

#include "widget.h"
#include "global.h"
#include "input.h"


int cellSize;

Alternative::Alternative(QWidget * widget) : Scene(widget)
{
    bomberman = new Dummy(9.5 * cellSize , 13 * cellSize);

    GUIElement* winLabel = new GUIElement(Coordinate(70, 100),
                              Coordinate(500,100),
                              "://assets/sprites/you_win.png");

    gui.push_back(winLabel);

    GUIElement* go = new GUIElement(Coordinate(70, 600),
                        Coordinate(500,100),
                        "://assets/sprites/t_game_over.png");

    gui.push_back(go);
}


Alternative::~Alternative()
{
    delete bomberman;

    // Delete all GUI elements
    for (std::list<GUIElement*>::iterator it = gui.begin(); it != gui.end(); it++)
    {
        delete (*it);
    }
}


void Alternative::update()
{
    bomberman->update();

    // Returns to the main menu when the START action is pressed
    if (Input::isActionJustPressed(START))
    {
        dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
    }
}


void Alternative::draw(QPainter * painter)
{
    // Drawing a background in a checkerboard pattern
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j, cellSize, cellSize,
                QBrush(QColor(0, 161, 30))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j + cellSize, cellSize, cellSize,
                QBrush(QColor(0, 161, 30))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j, cellSize, cellSize,
                QBrush(QColor(1, 133, 21))
            );

            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j + cellSize, cellSize, cellSize,
                QBrush(QColor(1, 133, 21))
            );
        }
    }

    bomberman->draw(painter);

    // Draw all GUI elements on top of the screen
    std::list<GUIElement*>::iterator it = gui.begin();
    while(it != gui.end())
    {
        (*it)->draw(painter);
        it++;
    }
}
