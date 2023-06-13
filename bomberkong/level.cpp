#include "level.h"

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
#include "powerup.h"
#include "textlabel.h"


Level::Level(QWidget* widget)
    : Scene(widget)
{
    itsPlayer = new PlayerCharacter(9.5 * cellSize, 21 * cellSize);
    createEntity(itsPlayer);

    // Add 3 hearts inside the GUI list to display them on screen
    int x = 10, y = 10;
    for (int i = 0; i != 3; i++)
    {
        gui.push_back
            (
                new GUIElement(
                Coordinate(x, y),
                Coordinate(32, 32),
                "://assets/sprites/t_full_heart.png"
            )
        );
        x += 40;
    }

    pauseLabel = new GUIElement(
        Coordinate(140, 620),
        Coordinate(350, 30),
        "://assets/sprites/t_press_start.png"
    );
    pauseLabel->isVisible = false; // The pause label is hidden until the game is paused
    gui.push_back(pauseLabel);

    bombOnScreenNb = 0;
}


Level::~Level()
{
    while (entities.size() != 0)
    {
        delete entities.back();
        entities.pop_back();
    }
}

void Level::update()
{
    // Displays the pause GUI if the game is paused
    if (isPaused)
    {
        pauseLabel->isVisible = true;
        return; // Doesn't update the level is the game is paused
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

void Level::updateLivesGUI(int playerLives)
{
    int i = 0;
    // Iterate the first three elements of the gui list (the hearts)
    for (std::list<GUIElement*>::iterator it = gui.begin(); it != gui.end() && i < 3; it++)
    {
        if (i > playerLives) // The player number of lives is less than i
        {
            (*it)->texture.load("://assets/sprites/t_empty_heart.png");
        }
        i++;
    }
}

void Level::initPowerUpGUI()
{
    int x = 10, y = 750; // The position of the power up list
    std::list<std::string> puSprites = {"t_speed", "t_explosion_time", "t_bomb_range", "t_bomb_nb"};

    for (std::list<std::string>::iterator it = puSprites.begin(); it != puSprites.end(); it++)
    {
        // Adds each power up inside the list
        std::string path = "://assets/sprites/" + (*it) + ".png";
        gui.push_back (
                new GUIElement(
                    Coordinate(x, y),
                    Coordinate(48, 48),
                    QString::fromStdString(path)
                )
        );
        // Power up counter
        gui.push_back(new TextLabel(x+20, y+65, 30, "x0", CENTER));
        x += 60;
    }

    GUIElement * armor = new GUIElement(Coordinate(x+335, y), Coordinate(48, 48), "://assets/sprites/t_armor.png");
    armor->isVisible = false; // Armor Power-Up is invisible while the player wear one
    gui.push_back(armor);
}

void Level::updatePowerUpGUI(int nb, PowerUpType type)
{
    std::string puNumber = "x" + to_string(nb);
    std::list<GUIElement*>::iterator it = gui.begin();

    switch(type)
    {
    case SPEED:
        std::advance(it, 5); // Advance of 5 elements until the right text label
        dynamic_cast<TextLabel*>(*it)->setText(QString::fromStdString(puNumber));
        break;

    case BOMB_TIME:
        std::advance(it, 7); // Advance of 7 elements until the right text label
        if (nb < 4)
        {
            dynamic_cast<TextLabel*>(*it)->setText(QString::fromStdString(puNumber));
        }
        else
        {
            dynamic_cast<TextLabel*>(*it)->setText("MAX");
        }
        break;

    case BOMB_RANGE:
        std::advance(it, 9); // Advance of 9 elements until the right text label
        if (nb < 5)
        {
            dynamic_cast<TextLabel*>(*it)->setText(QString::fromStdString(puNumber));
        }
        else
        {
            dynamic_cast<TextLabel*>(*it)->setText("MAX");
        }
        break;

    case BOMB_NB:
        std::advance(it, 11); // Advance of 11 elements until the right text label
        dynamic_cast<TextLabel*>(*it)->setText(QString::fromStdString(puNumber));
        break;

    case ARMOR:
        std::advance(it, 12); // Advance of 12 elements until the armor icon
        if (nb == 1)
        {
            (*it)->isVisible = true;
        }
        else
        {
            (*it)->isVisible = false;
        }
        break;

    default:
        break;
    }
}

void Level::draw(QPainter* painter)
{
    if(itsSceneType == TUTORIAL ||
        itsSceneType == ORIGINAL||
        itsSceneType == RELOADED||
        itsSceneType == BOMBERLAND||
        itsSceneType == JUNGLEDK)
    {
        // Draws a background in a checkerboard pattern
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 40; j++){
                painter->fillRect(
                    cellSize * 2 * i, cellSize * 2 * j - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(0, 161, 30))
                );

                painter->fillRect(
                    cellSize * 2 * i + cellSize, cellSize * 2 * j + cellSize - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(0, 161, 30))
                );

                painter->fillRect(
                    cellSize * 2 * i + cellSize, cellSize * 2 * j - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(1, 133, 21))
                );

                painter->fillRect(
                    cellSize * 2 * i, cellSize * 2 * j + cellSize - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(1, 133, 21))
                );
            }
        }
    }
    else if(itsSceneType == GLAGLA)
    {
        // Draws a background in a checkerboard pattern
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 40; j++){
                painter->fillRect(
                    cellSize * 2 * i, cellSize * 2 * j - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(180,207,250))
                    );

                painter->fillRect(
                    cellSize * 2 * i + cellSize, cellSize * 2 * j + cellSize - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(180,207,250))
                    );

                painter->fillRect(
                    cellSize * 2 * i + cellSize, cellSize * 2 * j - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(0,107,206))
                    );

                painter->fillRect(
                    cellSize * 2 * i, cellSize * 2 * j + cellSize - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(0,107,206 ))
                    );
            }
        }
    }
    else if(itsSceneType == CHOCHO)
    {
        // Draws a background in a checkerboard pattern
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 40; j++){
                painter->fillRect(
                    cellSize * 2 * i, cellSize * 2 * j - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(194, 16, 16))
                    );

                painter->fillRect(
                    cellSize * 2 * i + cellSize, cellSize * 2 * j + cellSize - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(194, 16, 16))
                    );

                painter->fillRect(
                    cellSize * 2 * i + cellSize, cellSize * 2 * j - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(230, 72, 72))
                    );

                painter->fillRect(
                    cellSize * 2 * i, cellSize * 2 * j + cellSize - cameraOffset.y - 30 * cellSize , cellSize, cellSize,
                    QBrush(QColor(230, 72, 72))
                    );
            }
        }
    }

    // Draws all the entities on screen
    std::list<Entity*>::iterator it = entities.begin();
    it++;
    while (it != entities.end())
    {
        (*it)->draw(painter);
        it++;
    }
    (*entities.begin())->draw(painter);

    // Draws every GUI elements on the screen
    std::list<GUIElement*>::iterator gui_it = gui.begin();
    while (gui_it != gui.end())
    {
        (*gui_it)->draw(painter);
        gui_it++;
    }
}


void Level::createEntity(Entity* entity)
{
    entity->setParent(this);
    if(typeid(*entity).name() == "Wall"  )
    {
        entity->setsprite();
    }
    entities.push_back(entity);
}


void Level::deleteAllEntity()
{
    // Delete an entity until the list isn't empty (keeps only the player character)
    while(entities.size() != 1)
    {
        delete entities.back();
        entities.pop_back();
    }
}


void Level::win()
{
    dynamic_cast<Widget*>(root)->switchScene(WIN_SCREEN); // Go to the victory screen
}


void Level::loose()
{
    dynamic_cast<Widget*>(root)->switchScene(LOOSE_SCREEN); // Go the the game over screen
}

void Level::alternative()
{
    dynamic_cast<Widget*>(root)->switchScene(ALTERNATIVE_ENDING); // Go to the alternative ending
}


void Level::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}


void Level::incrementBombNb()
{
    bombOnScreenNb++;
}


void Level::decrementBombNb()
{
    bombOnScreenNb--;
}

void Level::resetBombOnScreenNb()
{
    bombOnScreenNb = 0;
}

int Level::getBombOnScreenNb()
{
    return bombOnScreenNb;
}

std::list<Entity*> Level::getEntites()
{
    return entities;
}

PlayerCharacter* Level::getItsPlayer()
{
    return itsPlayer;
}


bool Level::isPointInWall(Coordinate pos)
{
    std::list<Entity*>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++)
    {
        if (dynamic_cast<Wall*>(*it) != nullptr || dynamic_cast<IndestructibleWall*>(*it) != nullptr)
        {
            if ((*it)->getRect().contains(pos.x, pos.y))
            {
                return true;
            }
        }
    }
    return false;
}
