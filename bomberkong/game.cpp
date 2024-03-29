#include "game.h"

#include <fstream>
#include <QDebug>
#include "widget.h"
#include "global.h"
#include "input.h"
#include "wall.h"
#include "bombergirl.h"
#include "playercharacter.h"
#include "donkeykong.h"
#include "indestructiblewall.h"
#include "explosion.h"


Original::Original(QWidget* widget)
    : Scene(widget)
{
    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));

    wMap = rand() % 3; // Select a random map

    pauseLabel = new GUIElement(
        Coordinate(140, 620),
        Coordinate(350, 30),
        "://assets/sprites/t_press_start.png"
    );
    pauseLabel->isVisible = false;
    gui.push_back(pauseLabel);

    restart(); // Initialize the level
}


Game::~Game()
{
    /*
    while (entities.size() != 0)
    {
        delete entities.back();
        entities.pop_back();
    }
    */
}


void Game::update()
{
    // Displays the pause GUI if the game is paused
    if (isPaused)
    {
        pauseLabel->isVisible = true;
        return;
    }
    else
    {
        pauseLabel->isVisible = false;
    }

    std::list<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        if ((*it)->isActive())
        {
            (*it)->update();

            // Collision detection made by iterating on every entity and checking if it's
            // rect intersects with this entity.
            std::list<Entity*>::iterator collider;
            for (collider = entities.begin(); collider != entities.end(); ++collider)
            {
                if (it != collider) // So that entities won't collide with themselves
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


void Game::draw(QPainter* painter)
{
    // Draws a background in a checkerboard pattern
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 13; j++){
            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j - cameraOffset + 416, cellSize, cellSize,
                QBrush(QColor(0, 161, 30))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j - cameraOffset + 416 + cellSize, cellSize, cellSize,
                QBrush(QColor(0, 161, 30))
            );

            painter->fillRect(
                cellSize * 2 * i + cellSize, cellSize * 2 * j - cameraOffset + 416, cellSize, cellSize,
                QBrush(QColor(1, 133, 21))
            );

            painter->fillRect(
                cellSize * 2 * i, cellSize * 2 * j + cellSize - cameraOffset + 416, cellSize, cellSize,

                QBrush(QColor(1, 133, 21))
            );
        }
    }

    // Draws entities below the GUI
    std::list<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        (*it)->draw(painter);
        it++;
    }

    std::list<GUIElement*>::iterator gui_it = gui.begin();
    while (gui_it != gui.end())
    {
        (*gui_it)->draw(painter);
        gui_it++;
    }
}


void Game::createEntity(Entity* entity)
{
    entity->setParent(this);
    entities.push_back(entity);
}


void Game::deleteAllEntity()
{
    // Delete an entity until the list isn't empty (keeps only the player character)
    while(entities.size() != 1)
    {
        delete entities.back();
        entities.pop_back();
    }
}


void Game::win()
{
    dynamic_cast<Widget*>(root)->switchScene(3); // Go to the victory screen
}


void Game::loose()
{
    dynamic_cast<Widget*>(root)->switchScene(4); // Go the the game over screen
}

void Game::alternative()
{
    dynamic_cast<Widget*>(root)->switchScene(5); // Go to the alternative ending
}


void Game::restart()
{
    deleteAllEntity();

    // Loads data from a file
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
}


void Game::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}
