#include "alternative.h"
#include "global.h"

Alternative::Alternative(QWidget * widget) : Scene(widget)
{
    bomberman = new Dummy(9.5 * cellSize , 13 * cellSize);

    GUIElement * winLabel = new GUIElement(Coordinate(70, 200),
                              Coordinate(500,100),
                              "://assets/sprites/you_win.png");

    gui.push_back(winLabel);

    GUIElement * go = new GUIElement(Coordinate(70, 200),
                        Coordinate(500,100),
                        "://assets/sprites/t_game_over.png");

    gui.push_back(go);
}

void Alternative::update()
{

}

void Alternative::draw(QPainter * painter)
{

}
