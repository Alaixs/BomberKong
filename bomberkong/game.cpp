#include "game.h"

#include <QDebug>

#include <fstream>

#include "wall.h"
#include "bombergirl.h"
#include "playercharacter.h"
#include "donkeykong.h"
#include "indestructiblewall.h"
#include "explosion.h"
#include "global.h"


Game::Game()
{
    int wMap = rand() % 3;

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
    createEntity(new PlayerCharacter(9.5 * cellSize, 21 * cellSize));
    createEntity(new BomberGirl(9.5 * cellSize, 6 * cellSize));
    createEntity(new DonkeyKong(9 * cellSize, 0));
}


void Game::update()
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
        qDebug() << entities.size();
        (*it)->draw(painter);
        it++;
    }
}


void Game::createEntity(Entity* entity)
{
    entity->setParent(this);
    entities.push_back(entity);
}


void Game::win()
{
    qDebug() << "gg";
}


void Game::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}
