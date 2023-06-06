// includes the necessary header files
#include "widget.h"

#include "ui_widget.h"
#include <fstream>
#include "input.h"
#include "playercharacter.h"
#include "demicharacter.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "explosion.h"
#include "bombergirl.h"
#include "donkeykong.h"
#include <QSoundEffect>
#include "soundmanager.h"
#include "guielement.h"
#include "pressstartlabel.h"
#include "logo.h"

#include "global.h"
extern const int cellSize;

Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);


    int height = 26 * cellSize;
    int width = 20 * cellSize;
    setFixedSize(width, height);

    srand(time(nullptr));

    // Choose a random Map
     wMap = rand() % 3;

     // preload sounds (avoid lag)
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_explosion.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_footsteps.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_mainTheme.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_loseTheme.wav");
     SoundManager::getInstance().loadSound("://assets/sounds/sfx_winTheme.wav");

    initMainMenu();
    //play main theme
    SoundManager::getInstance().playSound("://assets/sounds/sfx_mainTheme.wav", 0.03);

    // updates the game every 16ms
    connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    timer.start(16);

    initMainMenu();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::initMainMenu()
{
    gui.push_back(new Logo(Coordinate(82, 240)));
    gui.push_back(new PressStartLabel(Coordinate(140, 520)));
}


void Widget::initLevel1(){

    // Create level from file
    std::ifstream levelDataFile;
    levelDataFile.open("../bomberkong/assets/maps/Map.bkmap");

    if (!levelDataFile.is_open())
    {
        qDebug() << "Could not open the file";
    }

    char block;

    // Skip Until the right map
    for(int i=0;i<wMap;i++){
        while(levelDataFile >> block && block != '!'){};
    }

    int yPos = 4 * cellSize;
    int xPos = 0;
    while (levelDataFile >> block && block != '!')
    {
        if (block == ';')
        {
            yPos += cellSize;
            xPos = 0;

        }
        else
        {
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos));
            }
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos));
            }
            xPos += cellSize;
        }
    }

    levelDataFile.close();

    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));

    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize));

    createEntity(new DonkeyKong(9 * cellSize, 0));

}

void Widget::deleteEntities(){
    while(entities.size() != 0){
        entities.pop_back();
    }
}

void Widget::win(){
    deleteEntities();
    createEntity(new BomberGirl(504,528));
    createEntity(new Character(456,528));
}

void Widget::defeat(){
    deleteEntities();
    createEntity(new DonkeyKong(cellSize,528));
}

// Updating the Input class states
void Widget::keyPressEvent(QKeyEvent *ev)
{
    Input::keyPressedEvent(ev);
}


void Widget::keyReleaseEvent(QKeyEvent *ev)
{
    Input::keyReleasedEvent(ev);
}


void Widget::gameUpdate()
{
    if(state == MENU)
    {
        if(Input::isActionPressed(PAUSE) == false)
        {
            state = RUNNING;
            deleteEntities();
            initLevel1();
        }
    }
    else if(Input::isActionPressed(PAUSE) == false){
        std::list<Entity*>::iterator it = entities.begin();
        while (it != entities.end())
        {
            if ((*it)->isActive())
            {
                (*it)->update();

                // Collisions
                std::list<Entity*>::iterator collider;
                for (collider = entities.begin(); collider != entities.end(); ++collider)
                {
                    if (it != collider)
                    {
                        if ((*it)->getRect().intersects((*collider)->getRect()))
                        {
                            (*it)->collisionEvent(*collider);
                        }
                    }
                }

                ++it;
            }
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


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Fill the background with a color
    int width = cellSize;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 13; j++){
            painter.fillRect(
                width*2*i, width*2*j, width, width,
                QBrush(QColor(0, 161, 30))
                );

            painter.fillRect(
                width*2*i+cellSize, width*2*j+cellSize, width, width,
                QBrush(QColor(0, 161, 30))
                );

            painter.fillRect(
                width*2*i+cellSize, width*2*j, width, width,
                QBrush(QColor(1, 133, 21))
                );

            painter.fillRect(
                width*2*i, width*2*j+cellSize, width, width,
                QBrush(QColor(1, 133, 21))
                );
        }
    }

    if(state == MENU)
    {
        std::list<GUIElement *>::iterator it = gui.begin();
            while (it != gui.end()){
            (*it)->draw(&painter);
            it++;
        }
    }
    else if(state == RUNNING)
    {
        std::list<Entity*>::iterator it = entities.begin();
        while (it != entities.end())
        {
            // Draw the entity
            (*it)->draw(&painter);
            it++;
        }
        painter.end();
    }
    std::list<GUIElement*>::iterator gui_it = gui.begin();
    while (gui_it != gui.end())
    {
        // Draw the entity
        (*gui_it)->draw(&painter);
        gui_it++;
    }


    if(Input::isActionPressed(PAUSE) == true && state != MENU){
        QPainter * startPainter = new QPainter(this);
        Coordinate start(100,400);
        PressStartLabel label(start);
        label.draw(startPainter);
        startPainter->end();
    }

}


void Widget::createEntity(Entity * entity)
{
    entities.push_back(entity);
    entity->setParent(this);
}


void Widget::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}
