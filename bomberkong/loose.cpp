#include "loose.h"
#include "global.h"


Loose::Loose(QWidget* widget) : Scene(widget)
{
    dk = new DonkeyKong(8.5 * cellSize, 528);
    go = new GUIElement(Coordinate(70, 200),
                        Coordinate(500,100),
                        "://assets/sprites/t_game_over.png");
    //qDebug() << "coubeh";
}


void Loose::update()
{
    dk->update();
    dk->timer++;
}


void Loose::draw(QPainter * painter)
{
    painter->fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 0, 0)));

    int width = cellSize;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                width*2*i, width*2*j, width, width,
                QBrush(QColor(255, 0, 0))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j+cellSize, width, width,
                QBrush(QColor(255, 0, 0))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j, width, width,
                QBrush(QColor(200, 0, 0))
                );

            painter->fillRect(
                width*2*i, width*2*j+cellSize, width, width,
                QBrush(QColor(200, 0, 0))
                );
        }
    }

    dk->draw(painter);
    go->draw(painter);
}
