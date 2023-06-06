#include "loose.h"
#include "widget.h"
#include "global.h"


Loose::Loose(QWidget* widget) : Scene(widget)
{
    dk = new DonkeyKong(8.5 * cellSize, 528);
    go = new GUIElement(Coordinate(70, 200),
                        Coordinate(500,100),
                        "://assets/sprites/t_game_over.png");
    qDebug() << "coubeh";
}

void Loose::update()
{
    //dk->update();
}

void Loose::draw(QPainter * painter)
{
    dk->draw(painter);
    go->draw(painter);
}
