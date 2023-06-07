#include "tutorial.h"

#include <QDebug>

#include <fstream>

#include "input.h"
#include "wall.h"
#include "bombergirl.h"
#include "playercharacter.h"
#include "donkeykong.h"
#include "indestructiblewall.h"
#include "explosion.h"
#include "global.h"
#include "widget.h"


Tutorial::Tutorial(QWidget* widget)
    : Game(widget)
{
    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));
    restart();
}


void Tutorial::update()
{
    if(Input::isActionPressed(PAUSE) == false)
    {
        std::list<Entity*>::iterator it = entities.begin();
        while (it != entities.end())
        {
            if ((*it)->isActive())
            {
                (*it)->update();

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
    // start a loop with a duration while the vector entities isn't void
    while(entities.size() != 1)
    {
        delete entities.back();
        entities.pop_back();
    }
}


void Tutorial::win()
{
    dynamic_cast<Widget*>(root)->switchScene(1);
}


void Tutorial::loose()
{
    dynamic_cast<Widget*>(root)->switchScene(3);
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
    createEntity(new DonkeyKong(9 * cellSize, 0));

    startLabel = new GUIElement(Coordinate(140, 620),
                                Coordinate(350, 30),
                                QString("://assets/sprites/t_press_start.png"));

    gui.push_back(new GUIElement(
        Coordinate(450, 645),
        Coordinate(144, 96),
        QString("://assets/sprites/t_move_controls.png")
        ));
    gui.push_back(new GUIElement(
        Coordinate(40, 140),
        Coordinate(96, 48),
        QString("://assets/sprites/t_bomb_controls.png")
        ));

}


void Tutorial::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}
