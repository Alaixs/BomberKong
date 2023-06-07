#include "alternative.h"

#include "global.h"

Alternative::Alternative(QWidget * widget) : Scene(widget)
{
    bomberman = new Dummy(9.5 * cellSize , 13 * cellSize);

    GUIElement * winLabel = new GUIElement(Coordinate(70, 100),
                              Coordinate(500,100),
                              "://assets/sprites/you_win.png");

    gui.push_back(winLabel);

    GUIElement * go = new GUIElement(Coordinate(70, 600),
                        Coordinate(500,100),
                        "://assets/sprites/t_game_over.png");

    gui.push_back(go);
}

void Alternative::update()
{
    bomberman->update();
}

void Alternative::draw(QPainter * painter)
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

    bomberman->draw(painter);

    std::list<GUIElement*>::iterator it = gui.begin();
    while(it != gui.end())
    {
        (*it)->draw(painter);
        it++;
    }
}
