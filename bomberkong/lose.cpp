#include "lose.h"
#include "soundmanager.h"
#include "widget.h"
#include "global.h"
#include "input.h"


Lose::Lose(QWidget* widget) : Scene(widget)
{
    itsSceneType = LOOSE_SCREEN;
    setCameraOffset(Coordinate(9.5 * cellSize, 21 * cellSize - 256));

    changeLoseSound();
    dk = new DonkeyKong(8.5 * cellSize, 528);
    dk->setParent(this);

    go = new GUIElement(
                Coordinate(70, 200),
                Coordinate(500,100),
                "://assets/sprites/t_game_over.png"
            );
}


Lose::~Lose()
{
    delete dk;
    delete go;
}


void Lose::update()
{
    dk->update();
    dk->timer++;

    if (Input::isActionJustPressed(START))
    {
        changeOSTSound();
        dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
    }
}


void Lose::draw(QPainter * painter)
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

    dk->draw(painter);
    go->draw(painter);
}

void Lose::changeLoseSound()
{
    SoundManager::getInstance().stopSound("://assets/sounds/sfx_mainTheme.wav");
    SoundManager::getInstance().playSound("://assets/sounds/sfx_loseTheme.wav", 0.5, false);
}

void Lose::changeOSTSound()
{
    SoundManager::getInstance().stopSound("://assets/sounds/sfx_loseTheme.wav");
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03, true);
}
