#include "game.h"

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


Game::Game(QWidget* widget)
    : Scene(widget)
{
    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));

    wMap = rand() % 3;

    restart();
}

Game::~Game()
{
    while (entities.size() != 0)
    {
        delete entities.back();
        entities.pop_back();
    }
}

void Game::update()
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


void Game::draw(QPainter* painter)
{
    painter->fillRect(QRect(0, 0, 50, 50), QBrush(QColor(255, 0, 0)));

    int width = cellSize;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                width*2*i, width*2*j, width, width,
                QBrush(QColor(0, 161, 30))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j+cellSize, width, width,
                QBrush(QColor(0, 161, 30))
                );

            painter->fillRect(
                width*2*i+cellSize, width*2*j, width, width,
                QBrush(QColor(1, 133, 21))
                );

            painter->fillRect(
                width*2*i, width*2*j+cellSize, width, width,
                QBrush(QColor(1, 133, 21))
                );
        }
    }

    std::list<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        (*it)->draw(painter);
        it++;
    }

    std::list<GUIElement*>::iterator gui_it = gui.begin();
    while (gui_it != gui.end())
    {
        qDebug() << "gui";
        (*gui_it)->draw(painter);
        gui_it++;
    }

    if(Input::isActionPressed(PAUSE) == true)
    {
        startLabel->draw(painter);
    }
}


void Game::createEntity(Entity* entity)
{
    entity->setParent(this);
    entities.push_back(entity);
}


void Game::deleteAllEntity()
{
    // start a loop with a duration while the vector entities isn't void
    while(entities.size() != 1)
    {
        delete entities.back();
        entities.pop_back();
    }
}


void Game::win()
{
    dynamic_cast<Widget*>(root)->switchScene(3);
}


void Game::loose()
{
    dynamic_cast<Widget*>(root)->switchScene(4);
}

void Game::alternative()
{
    dynamic_cast<Widget*>(root)->switchScene(5);
}


void Game::restart()
{
    deleteAllEntity();

    std::ifstream levelDataFile;
    levelDataFile.open("../bomberkong/assets/maps/Map.bkmap");

    if (!levelDataFile.is_open())
        qDebug() << "Could not open the file";


    // Iterate on every character of the file and place the corresponding block,
    // Goes on the next line when encountering a semicolon;
    char block;

    for(int i = 0; i < wMap; i++)
    {
        while(levelDataFile >> block && block != '!'){};
    }

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



}


void Game::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}
