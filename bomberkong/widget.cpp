// Include the QT file
#include <fstream>
#include <QSoundEffect>

#include "alternative.h"
#include "global.h"

// includes the necessary header files
#include "loose.h"
#include "widget.h"
#include "ui_widget.h"
#include "input.h"
#include "soundmanager.h"
#include "game.h"
#include "mainmenu.h"
#include "win.h"
#include "tutorial.h"


Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

    cellSize = 32;
    isPaused = false;
    wLvl = 0;



    // Screen dimensions
    int height = 26 * cellSize;
    int width = 20 * cellSize;

    setFixedSize(width, height);

    srand(time(nullptr));

    // preload sounds (avoid lag)
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_explosion.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_footsteps.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_mainTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_loseTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_winTheme.wav");

    //play main theme
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03);

    // Set the first scene to be the main menu
    currentScene = new MainMenu(this);

    connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    timer.start(16); // Approx. 16ms
}


Widget::~Widget()
{
    delete ui;
}

// Updating the Input class states
void Widget::keyPressEvent(QKeyEvent *ev)
{ Input::keyPressedEvent(ev); }

void Widget::keyReleaseEvent(QKeyEvent *ev)
{Input::keyReleasedEvent(ev); }


// Updating the entities and the game
void Widget::gameUpdate()
{
    currentScene->update();

    // Draw a frame
    repaint(0, 0, 1532, 1056);
}

// Draw a single frame
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    currentScene->draw(&painter);
}


void Widget::switchScene(int sceneId)
{
    Scene * temp = currentScene;

    switch (sceneId)
    {
        case 0:
            currentScene = new MainMenu(this);
        break;

        case 1:
            currentScene = new Tutorial(this);
        break;

        case 2:
            currentScene = new Game(this);
        break;

        case 3:
            currentScene = new Win(this);
        break;

        case 4:
            currentScene = new Loose(this);
        break;

        case 5:
            currentScene = new Alternative(this);
        break;
    }

    delete temp;
}
