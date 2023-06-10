#include "loose.h"

#include <fstream>
#include <QSoundEffect>
#include <QFontDatabase>
#include "ui_widget.h"
#include "global.h"
#include "widget.h"
#include "soundmanager.h"
#include "input.h"
#include "original.h"
#include "alternative.h"
#include "mainmenu.h"
#include "win.h"
#include "tutorial.h"
#include "reloaded.h"


bool isPaused;

Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

    gameFont = QFontDatabase::addApplicationFont("://assets/fonts/upheavtt.ttf");

    cellSize = 32;
    isPaused = false;

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
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03, true);

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
{
    Input::keyPressedEvent(ev);
    if (ev->key() == Qt::Key_Escape)
    {
        isPaused = !isPaused; // Toggle the pause
    }
}

void Widget::keyReleaseEvent(QKeyEvent *ev)
{Input::keyReleasedEvent(ev); }


// Updating the entities and the game
void Widget::gameUpdate()
{
    currentScene->update();

    // Draw a frame
    repaint(0, 0, 1532, 1056);

    Input::resetFLInputs();
}


// Draw a single frame
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    currentScene->draw(&painter);
}


void Widget::switchScene(SceneType sceneType)
{
    //Scene * temp = currentScene;

    switch (sceneType)
    {
        case MAIN_MENU:
            currentScene = new MainMenu(this);
        break;

        case OPTIONS:
            //TODO
            break;

        case TUTORIAL:
            currentScene = new Tutorial(this);
        break;

        case ORIGINAL:
            currentScene = new Original(this);
        break;

        case RELOADED:
            currentScene = new Reloaded(this);
            break;

        case WIN_SCREEN:
            currentScene = new Win(this);
        break;

        case LOOSE_SCREEN:
            currentScene = new Loose(this);
        break;

        case ALTERNATIVE_ENDING:
            currentScene = new Alternative(this);
        break;
    }

    //delete temp;
}
