#include "loose.h"
#include "soundmanager.h"
#include "global.h"


Loose::Loose(QWidget* widget) : Scene(widget)
{
    changeSound();
    dk = new DonkeyKong(8.5 * cellSize, 528);
    go = new GUIElement(
                Coordinate(70, 200),
                Coordinate(500,100),
                "://assets/sprites/t_game_over.png"
            );
}


Loose::~Loose()
{
    delete dk;
    delete go;
}


void Loose::update()
{
    dk->update();
    dk->timer++;
}


void Loose::draw(QPainter * painter)
{
    // Draws a background in a checkerboard pattern
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j, cellSize, cellSize,
                QBrush(QColor(255, 0, 0))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j + cellSize, cellSize, cellSize,
                QBrush(QColor(255, 0, 0))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j, cellSize, cellSize,
                QBrush(QColor(200, 0, 0))
            );

            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j + cellSize, cellSize, cellSize,
                QBrush(QColor(200, 0, 0))
            );
        }
    }

    //dk->draw(painter);
    go->draw(painter);
}

void Loose::changeSound()
{
    SoundManager::getInstance().stopSound("://assets/sounds/sfx_mainTheme.wav");
    SoundManager::getInstance().playSound("://assets/sounds/sfx_loseTheme.wav", 0.5, false);
}
