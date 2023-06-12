#include "tutorial.h"

#include <QDebug>
#include <fstream>
#include "hammer.h"
#include "input.h"
#include "global.h"
#include "widget.h"
#include "wall.h"
#include "bombergirl.h"
#include "playercharacter.h"
#include "donkeykong.h"
#include "indestructiblewall.h"
#include "explosion.h"


Tutorial::Tutorial(QWidget* widget)
    : Level(widget)
{
    itsSceneType = TUTORIAL;
    setOffsetLimit(21*cellSize, 21*cellSize);

    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));
    restart();
}

Tutorial::~Tutorial()
{

}

void Tutorial::update()
{
    // Display the pause GUI if the game is paused
    if (isPaused)
    {
        pauseLabel->isVisible = true;
        return;
    }
    else
    {
        pauseLabel->isVisible = false;
    }

    if(Input::isActionPressed(PAUSE) == false)
    {
        std::list<Entity*>::iterator it = entities.begin();
        while (it != entities.end())
        {
            if ((*it)->isActive())
            {
                (*it)->update();

                // Collision detection
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
                it = entities.erase(it);
            }
        }
    }
}


void Tutorial::createEntity(Entity* entity)
{
    entity->setParent(this);
    entities.push_back(entity);
}


void Tutorial::deleteAllEntity()
{
    // Delete all the entities axcept the player character
    while(entities.size() != 1)
    {
        delete entities.back();
        entities.pop_back();
    }
}


void Tutorial::win()
{
    dynamic_cast<Widget*>(root)->switchScene(WIN_SCREEN);
}


void Tutorial::loose()
{
    dynamic_cast<Widget*>(root)->switchScene(LOOSE_SCREEN);
}



void Tutorial::restart()
{
    deleteAllEntity();

    std::ifstream levelDataFile;
    levelDataFile.open("../bomberkong/assets/maps/tutorial.bkmap");

    if (!levelDataFile.is_open())
        qDebug() << "Could not open the file";


    // Iterate on every character of the file and place the corresponding block,
    // Goes on the next line when encountering a semicolon;
    char block;

    int yPos = 4 * cellSize;
    int xPos = 0;

    while (levelDataFile >> block && block != '!')
    {
        if (block == ';')
        {
            // Line break
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

    // Create characters at their spawn points

    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize));

    createEntity(new Hammer(2.5 * cellSize, 18 * cellSize));

    DonkeyKong * dk = new DonkeyKong(9 * cellSize, 0);
    dk->setParent(this);
    dk->throwingRate = 200;
    entities.push_back(dk);

    startLabel = new GUIElement(Coordinate(140, 620),
                                Coordinate(350, 30),
                                QString("://assets/sprites/t_press_start.png"));

    gui.push_back(new GUIElement(
        Coordinate(425, 600),
        Coordinate(208, 128),
        QString("://assets/sprites/t_move_controls.png")
        ));
    gui.push_back(new GUIElement(
        Coordinate(40, 140),
        Coordinate(132, 140),
        QString("://assets/sprites/t_bomb_controls.png")
        ));

}


void Tutorial::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}


void Tutorial::nextLvl()
{
    dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
}
