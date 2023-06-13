#include "glagla.h"
#include "lose.h"

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
#include "settingsmenu.h"
#include "bomberland.h"
#include "load.h"

bool isPaused;

Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

    setWindowTitle("BomberKong Reloaded");

    // Loads the font used by the TextLabel object
    gameFont = QFontDatabase::addApplicationFont("://assets/fonts/upheavtt.ttf");

    // Set the control scheme according to config.ini
    Input::loadControlsConfig();

    cellSize = 32;

    // The scenes inherited from the Level class will no be updated
    // if isPaused is set to true
    isPaused = false;

    // Screen dimensions
    int height = 26 * cellSize;
    int width = 20 * cellSize;

    setFixedSize(width, height);

    srand(time(nullptr)); // Initializing the rng

    // preload sounds (avoid lag)
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_explosion.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_footsteps.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_mainTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_loseTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_winTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_select.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_powerUp.wav");

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


void Widget::keyPressEvent(QKeyEvent *ev)
{
    // Updating the Input class states
    Input::keyPressedEvent(ev);

    if (ev->key() == Qt::Key_Escape)
    {
        isPaused = !isPaused; // Toggle the pause
    }
}

void Widget::keyReleaseEvent(QKeyEvent *ev)
{
    // Updating the Input class states
    Input::keyReleasedEvent(ev);
}


// Updating the entities and the game
void Widget::gameUpdate()
{
    currentScene->update();

    // Draw a frame
    repaint(0, 0, 1532, 1056);

    // Reset all non persistant inputs
    // This is the last instruction of a tick
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
    // Sets a pointer to the current scene to delete it after switching
    Scene * temp = currentScene;

    switch (sceneType)
    {
        case MAIN_MENU:
            currentScene = new MainMenu(this);
        break;

        case OPTIONS:
            currentScene = new SettingsMenu(this);
        break;

        case LOAD:
            currentScene = new Load(this);
            break;

        case TUTORIAL:
            currentScene = new Glagla(this);
        break;

        case ORIGINAL:
            currentScene = new Original(this);
        break;

        case RELOADED:
            currentScene = new Reloaded(this);
            break;

        case BOMBERLAND:
            currentScene = new BomberLand(this);
            break;

        case WIN_SCREEN:
            currentScene = new Win(this);
        break;

        case LOOSE_SCREEN:
            currentScene = new Lose(this);
        break;

        case ALTERNATIVE_ENDING:
            currentScene = new Alternative(this);
        break;
    }

    //delete temp;
}
