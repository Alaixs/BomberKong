// Include the QT file
#include <fstream>
#include <QSoundEffect>


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
#include "pressstartlabel.h"
#include "logo.h"
#include "gameover.h"
#include "youwin.h"

// Include the global variable
#include "global.h"
extern const int cellSize;

// Widget initialiser
// Initialise all that are gonne use in widget class
Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

    // Initialise the Height in pixel of the window
    int height = 26 * cellSize;

    // Initialise the Width in pixel of the window
    int width = 20 * cellSize;

    // Set the permanent size of the window
    // No modification possible by user
    setFixedSize(width, height);

    // Set a new rand sequences, use time for more random
    srand(time(nullptr));

    // Choose a random Map
     wMap = rand() % 3;

     // preload sounds (avoid lag)
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_explosion.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_footsteps.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_mainTheme.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_loseTheme.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_winTheme.wav");

     //Initialise the Menu
    initMainMenu();

    //play main theme
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03);

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

// Initiliase the main menu and all of his attribute/entities
void Widget::initMainMenu()
{
    // Add the Logo to the list
    gui.push_back(new Logo(Coordinate(82, 240)));

    // Add the press start label in the list
    gui.push_back(new PressStartLabel(Coordinate(140, 520)));
}

// Initiliase the Level and all of his attribute/entities
void Widget::initLevel1()
{

    // Create level from file
    std::ifstream levelDataFile;

    // Open Data file
    levelDataFile.open("../bomberkong/assets/maps/Map.bkmap");

    // Chek if the Data file is really open
    if (!levelDataFile.is_open())
    {
        qDebug() << "Could not open the file";
    }

    // Init an iterator who's gonna get on all char in the file
    char block;

    // Skip Until the right map
    for(int i=0;i<wMap;i++){
        while(levelDataFile >> block && block != '!'){};
    }

    // Init the position of the first Block
    int yPos = 4 * cellSize;
    int xPos = 0;

    // Read the File and place the good block
    while (levelDataFile >> block && block != '!')
    {
        // End of line, reset the xPos and get int the next line
        if (block == ';')
        {
            yPos += cellSize;
            xPos = 0;

        }
        else
        {
            // If 2 in file place wall
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos));
            }
            // If 1 place Indestructible wall
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos));
            }
            // If 0 place nothong

            // Move to next cell
            xPos += cellSize;
        }
    }

    // Close the file
    levelDataFile.close();

    // Create an instance of a playable bomberman on the spawn point
    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));

    // Create an instance of a bombergirl
    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize));

    // Create a Donkey above the maps
    createEntity(new DonkeyKong(9 * cellSize, 0));

}

// Delete all the actual entities
void Widget::deleteEntities(){
    // start a loop with a duration while the vector entities isn't void
    while(entities.size() != 0){
        // delete the actual last entities
        entities.pop_back();
    }
}

// Destroy the Level 1 and initialise the winning screen
void Widget::win(){
    // delete all entities
    deleteEntities();

    // create an unplayable bomberman
    createEntity(new Character(10 * cellSize, 16 * cellSize));

    // create a bombergirl
    createEntity(new BomberGirl(9 * cellSize, 16 * cellSize));

    // Set the win boolean to true
    isWin = true;

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
    // Check if the game is the menu
    if(state == MENU)
    {
        // Check if the player want to start the game
        // Use the KEy "P"
        if(Input::isActionPressed(PAUSE) == false )
        {
            // Delete the logo from gui
            gui.pop_back();
            // set state to running
            state = RUNNING;
            // delete all actual entities
            deleteEntities();
            // Start the level 1
            initLevel1();
        }
    }
    // If the game is not in a menu, check if it's running
    else if(state == RUNNING)
    {
        // Check if the player loose
        if(nbLive == -1)
        {
            //delete all entities
            deleteEntities();

            // Create a Donkey Kong
            createEntity(new DonkeyKong(8.5*cellSize,528));

            // Decrease by one the Number of live (-2)
            // Do this to not return in this possibility
            nbLive--;
        }
    }

    // Check if the game isn't pause
    // Pause aren't possible while the winning screen is display
    if(Input::isActionPressed(PAUSE) == false || isWin == true){
        // Create an iterator and set it a the beginning of the vextor entities
        std::list<Entity*>::iterator it = entities.begin();
        // Create a loop while the iterator isn't equal to the last entities in the vector
        while (it != entities.end())
        {
            // Check if the entity is Enable
            if ((*it)->isActive())
            {
                // Update the cracteristic of the entity :
                // - Coordinate
                // - Frame
                // - etc
                (*it)->update();

                // Set an iterator on the collision possible list
                std::list<Entity*>::iterator collider;

                // Set a loop where the iterator will get on all entities to check the collision
                for (collider = entities.begin(); collider != entities.end(); ++collider)
                {
                    // Check if the entitie isn't equal to the collider
                    if (it != collider)
                    {
                        // Check if the two hitboxes of the entities are in collision
                        if ((*it)->getRect().intersects((*collider)->getRect()))
                        {
                            // Do the collider function for this collision type
                            // Define in the entities class
                            (*it)->collisionEvent(*collider);
                        }
                    }
                }

                // Pass on the next entities
                ++it;
            }
            // if the entity isn't enable
            else
            {
                //delete *it;
                it = entities.erase(it);
            }
        }
    }

    // Draw a frame
    repaint(0, 0, 1532,1056);
}

// Updating the screening display
void Widget::paintEvent(QPaintEvent *)
{
    // Create a painter to draw the entities
    QPainter painter(this);

    // Fill the background with a color
    // Set the with of cell to cellSize
    int width = cellSize;
    // Start a loop with an iteration's number equal to the number of cell in the width's cell number
    for(int i = 0; i < 20; i++){

        // Start a loop with an iteration's number equal to the hal of the Heigth's number cell
        for(int j = 0; j < 13; j++){
            // Paint a rectangle with the dimension of a cell
            // Paint it in the current line and column of the loops
            // Paint it with the first color
            painter.fillRect(
                width*2*i, width*2*j, width, width,
                QBrush(QColor(0, 161, 30))
                );

            // Paint a rectangle with the dimension of a cell
            // Paint it in the next line and next column of the loops
            // Paint it with the first color
            painter.fillRect(
                width*2*i+cellSize, width*2*j+cellSize, width, width,
                QBrush(QColor(0, 161, 30))
                );

            // Paint a rectangle with the dimension of a cell
            // Paint it in the next line and current column of the loops
            // Paint it with the second color
            painter.fillRect(
                width*2*i+cellSize, width*2*j, width, width,
                QBrush(QColor(1, 133, 21))
                );

            // Paint a rectangle with the dimension of a cell
            // Paint it in the current line and next column of the loops
            // Paint it with the second color
            painter.fillRect(
                width*2*i, width*2*j+cellSize, width, width,
                QBrush(QColor(1, 133, 21))
                );
        }
    }

    // Check the actual game's state
    if(state == MENU)
    {
        // Set an iterator on the first guielement in gui
        std::list<GUIElement *>::iterator it = gui.begin();
        // Create a loop while iterator isn't at the end of the vector
            while (it != gui.end())
        {
            // Draw the actual iterator
            (*it)->draw(&painter);

            // Step in the next guielement
            it++;
        }
    }
    // If the Game is running and the player still have live
    else if(state == RUNNING && nbLive > -1 )
    {
        // Create an iterator of entities
        // Set it on the first entities
        std::list<Entity*>::iterator it = entities.begin();
        while (it != entities.end())
        {
            // Draw the entity
            (*it)->draw(&painter);
            // Pass on the next entity
            it++;
        }

        // Check the isWin status of the player
        if(isWin){
            // Create a Win Gui
            YouWin win (Coordinate(82, 240));

            // Draw it
            win.draw(&painter);
        }
    }
    // If the player hasn't any live left
    if(nbLive < 0){
        // Create the game over gui
        GameOver go (Coordinate(82, 240));

        // Draw it
        go.draw(&painter);

        // Only one entities actually in the vector
        // Draw it
        (*entities.begin())->draw(&painter);
    }

    // End the painter
    painter.end();

    // Set an iterator on the first element of gui vector
    std::list<GUIElement*>::iterator gui_it = gui.begin();

    // Create a loop while iterator isn't on the last element
    while (gui_it != gui.end())
    {
        // Draw the gui
        (*gui_it)->draw(&painter);

        // Get on the next Gui
        gui_it++;
    }

    // Check if the is Paused, the player still have live and hasn't won yet
    if(Input::isActionPressed(PAUSE) == true && state != MENU && nbLive > -1 && isWin != true){

        // Create a new painter
        // A pointer this time
        QPainter * startPainter = new QPainter(this);

        // Create the coordinate
        Coordinate start(100,400);

        // Create the start label gui at the coordinate start
        PressStartLabel label(start);

        // Show the label
        label.draw(startPainter);

        // End the painter
        startPainter->end();
    }

}

// Create an entities
void Widget::createEntity(Entity * entity)
{
    // create an entities and push him at the end of the vector entities
    // Constructor used os the entitis's type constructor
    entities.push_back(entity);

    // Set the parent of the entity to widget
    entity->setParent(this);
}

// Create an explosion
void Widget::createExplosion(int posX, int posY)
{
    // Create an entity with the Explosion type
    // Use for dynamic cast
    createEntity(new Explosion(posX, posY));
}
