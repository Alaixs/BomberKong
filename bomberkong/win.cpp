#include "win.h"
#include "global.h"
#include "widget.h"

Win::Win(QWidget * widget) : Scene(widget)
{
    bomberman = new Character(9 * cellSize , 16 * cellSize);
    bombergirl = new BomberGirl(10 * cellSize, 16 * cellSize);
    winLabel = new GUIElement(Coordinate(70, 200),
                        Coordinate(500,100),
                        "://assets/sprites/you_win.png");
}

Win::~Win()
{
    delete bomberman;
    delete bombergirl;
    delete winLabel;
}

void Win::update()
{
    bomberman->update();
    bombergirl->update();
}

void Win::draw(QPainter * painter)
{
    painter->fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 0, 0)));

    int width = cellSize;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                width*2*i, width*2*j, width, width,
                QBrush(QColor(250, 250, 0))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j+cellSize, width, width,
                QBrush(QColor(250, 250, 0))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j, width, width,
                QBrush(QColor(200, 200, 0))
                );

            painter->fillRect(
                width*2*i, width*2*j+cellSize, width, width,
                QBrush(QColor(200, 200, 0))
                );
        }
    }

    bomberman->draw(painter);
    bombergirl->draw(painter);
    winLabel->draw(painter);
}
