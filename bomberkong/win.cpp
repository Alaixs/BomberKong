#include "win.h"
#include "widget.h"
#include "global.h"
#include "input.h"

Win::Win(QWidget * widget) : Scene(widget)
{
    changeWinSound();
    itsSceneType = WIN_SCREEN;
    setCameraOffset(Coordinate(9.5 * cellSize, 21 * cellSize - 256));

    bomberman = new Dummy(9 * cellSize , 16 * cellSize);
    bombergirl = new BomberGirl(10 * cellSize, 16 * cellSize);
    bombergirl->setParent(this);

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

    if (Input::isActionJustPressed(START))
    {
        changeOSTSound();
        dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
    }
}

void Win::draw(QPainter * painter)
{
    // Draws a background in a checkerboard pattern
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j, cellSize, cellSize,
                QBrush(QColor(255, 215, 0))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j + cellSize, cellSize, cellSize,
                QBrush(QColor(255, 215, 0))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j, cellSize, cellSize,
                QBrush(QColor(230, 198, 25))
            );

            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j + cellSize, cellSize, cellSize,
                QBrush(QColor(230, 198, 25))
            );
        }
    }

    bomberman->draw(painter);
    bombergirl->draw(painter);
    winLabel->draw(painter);
}

void Win::changeWinSound()
{
    SoundManager::getInstance().stopSound("://assets/sounds/sfx_mainTheme.wav");
    SoundManager::getInstance().stopSound("://assets/sounds/sfx_ostBossBattle.wav");
    SoundManager::getInstance().playSound("://assets/sounds/sfx_winTheme.wav", 0.3, false, true);
}

void Win::changeOSTSound()
{
    SoundManager::getInstance().stopSound("://assets/sounds/sfx_winTheme.wav");
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03, false, true);
}
