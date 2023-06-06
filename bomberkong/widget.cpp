// Include the QT file
#include <fstream>
#include <QSoundEffect>

#include "global.h"

// includes the necessary header files
#include "widget.h"
#include "ui_widget.h"
#include "input.h"
#include "playercharacter.h"
#include "demicharacter.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "explosion.h"
#include "bombergirl.h"
#include "donkeykong.h"
#include "soundmanager.h"
#include "guielement.h"
#include "game.h"
#include "mainmenu.h"

// Include the global variable

//extern const int cellSize;

// Widget initialiser
// Initialise all that are gonne use in widget class
Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

    cellSize = 32;

    // Initialise the Height in pixel of the window
    int height = 26 * cellSize;

    // Initialise the Width in pixel of the window
    int width = 20 * cellSize;

    // Set the permanent size of the window
    // No modification possible by user
    setFixedSize(width, height);

    // Set a new rand sequences, use time for more random
    srand(time(nullptr));


    // preload sounds (avoid lag)
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_explosion.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_footsteps.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_mainTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_loseTheme.wav");
    SoundManager::getInstance().loadSound("://assets/sounds/sfx_winTheme.wav");

    //play main theme
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03);

    currentScene = new MainMenu(this);

    // Link The timer
    connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));

    // Start the timer to have a frame each 16 ms
    timer.start(16);
}

// Destructor
Widget::~Widget()
{
    delete ui;
}




// Delete all the actual entities
void Widget::deleteEntities(){
    // start a loop with a duration while the vector entities isn't void
    while(entities.size() != 0){
        // delete the actual last entities
        entities.pop_back();
    }
}


// Updating the Input class states
void Widget::keyPressEvent(QKeyEvent *ev)
{
    // Check the keypress event of Input class
    Input::keyPressedEvent(ev);
}


// Updating the Input class states
void Widget::keyReleaseEvent(QKeyEvent *ev)
{
    // Check the release event of Input class
    Input::keyReleasedEvent(ev);
}


// Updating the entities and the game
void Widget::gameUpdate()
{
    currentScene->update();

    // Draw a frame
    repaint(0, 0, 1532, 1056);
}

// Updating the screening display
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    currentScene->draw(&painter);
}


void Widget::switchScene(int sceneId)
{
    delete currentScene;

    switch (sceneId)
    {
        case 0:
            currentScene = new MainMenu(this);
        break;

        case 1:
            currentScene = new Game(this);
        break;
    }
}
