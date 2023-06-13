#include "load.h"
#include "widget.h"
#include "textlabel.h"
#include "input.h"
#include "powerup.h"
#include "global.h"

Load::Load(QWidget* root)
    : Scene(root)
{
    itsSaveFile.open("../bomberkong/save.bksave"); // Save file
    if (!itsSaveFile)
    {
        qDebug("Unable to load the save file.");
    }
    else
    {
        while (!itsSaveFile.eof())
        {
            // Read and store the data from the save file
            itsSaveFile >> level >> lives >> speed >> bombTime >> bombRange >> bombNb >> wearArmor;
        }
        itsSaveFile.close();
    }

    // Background
    bg = new GUIElement(Coordinate(0, 0),
                        Coordinate(832, 832),
                        QString("://assets/sprites/t_menu_bg.png")
                        );
    gui.push_back(bg);

    // Create all the text labels
    gui.push_back(new TextLabel(320, 75, 64, "Load", CENTER));
    gui.push_back(new TextLabel(50, 160, 48, "Level", LEFT));
    gui.push_back(new TextLabel(50, 370, 48, "Life", LEFT));
    gui.push_back(new TextLabel(50, 470, 48, "Power-Up", LEFT));
    gui.push_back(new TextLabel(50, 610, 48, "Armor", LEFT));

    // Choices text labels
    choiceReturn = new TextLabel(100, 750, 48, "Return", LEFT);
    gui.push_back(choiceReturn);
    choiceConfirm = new TextLabel(350, 750, 48, "Confirm", LEFT);
    gui.push_back(choiceConfirm);

    // Default selection
    choiceReturn->select();
    choiceReturn->setColor(Qt::red);

    // Level thumbnail
    switch(level)
    {
    case 0: // Chocho
        gui.push_back(
            new GUIElement(
                Coordinate(50, 175),
                Coordinate(540, 150),
                "://assets/sprites/t_chocho_thumbnail.png"
                )
            );
        break;
    case 1: // Glagla
        gui.push_back(
            new GUIElement(
                Coordinate(50, 175),
                Coordinate(540, 150),
                "://assets/sprites/t_glagla_thumbnail.png"
                )
            );
        break;
    case 2: // Jungle DK
        gui.push_back(
            new GUIElement(
                Coordinate(50, 175),
                Coordinate(540, 150),
                "://assets/sprites/t_jungle_thumbnail.png"
                )
            );
        break;

    default:
        break;
    }

    // Life
    int x = 50, y = 380;
    for (int i = -1; i != 2; i++)
    {
        if (i < lives)
        {
            gui.push_back(
                new GUIElement(
                    Coordinate(x, y),
                    Coordinate(48, 48),
                    "://assets/sprites/t_full_heart.png"
                    )
                );
        }
        else
        {
            gui.push_back(
                new GUIElement(
                    Coordinate(x, y),
                    Coordinate(48, 48),
                    "://assets/sprites/t_empty_heart.png"
                    )
                );
        }
        x += 60;
    }

    // Power-Up
    x = 50, y = 490; // The position of the power up list
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
        x += 60;
    }

    // Display the number of every Power-Up
    displayPUNumber(speed, SPEED, 70, 555);
    displayPUNumber(bombTime, BOMB_TIME, 130, 555);
    displayPUNumber(bombRange, BOMB_RANGE, 190, 555);
    displayPUNumber(bombNb, BOMB_NB, 250, 555);

    // Add the armor icon with a text label "ON" if the player has one, "OFF" otherwise
    GUIElement * armor = new GUIElement(Coordinate(50, 625), Coordinate(48, 48), "://assets/sprites/t_armor.png");
    gui.push_back(armor);

    if (wearArmor)
    {
        gui.push_back(new TextLabel(150, 660, 48, "ON", CENTER));
    }
    else
    {
        gui.push_back(new TextLabel(150, 660, 48, "OFF", CENTER));
    }
}


Load::~Load()
{
    // Loop to delete every elements inside the gui list
    for (std::list<GUIElement*>::iterator it = gui.begin(); it != gui.end(); it++)
    {
        delete (*it); // Delete the current element of the list
    }
    gui.clear();
}


void Load::displayPUNumber(int nb, PowerUpType type, int x, int y)
{
    std::string puNumber = "x" + std::to_string(nb);

    switch(type) // Update the right text label based on the Power-Up type
    {
    case SPEED:
        if (nb < 4)
        {
            gui.push_back(new TextLabel(x, y, 30, QString::fromStdString(puNumber), CENTER));
        }
        else
        {
            gui.push_back(new TextLabel(x, y, 30, "MAX", CENTER));
        }
        break;

    case BOMB_TIME:
        if (nb < 4)
        {
            gui.push_back(new TextLabel(x, y, 30, QString::fromStdString(puNumber), CENTER));
        }
        else
        {
            gui.push_back(new TextLabel(x, y, 30, "MAX", CENTER));
        }
        break;

    case BOMB_RANGE:
        if (nb < 5)
        {
            gui.push_back(new TextLabel(x, y, 30, QString::fromStdString(puNumber), CENTER));
        }
        else
        {
            gui.push_back(new TextLabel(x, y, 30, "MAX", CENTER));
        }
        break;

    case BOMB_NB:
        gui.push_back(new TextLabel(x, y, 30, QString::fromStdString(puNumber), CENTER));
        break;

    default:
        break;
    }
}


void Load::update()
{
    if (Input::isActionJustPressed(MOVE_RIGHT) || Input::isActionJustPressed(MOVE_LEFT))
    {
        if (choiceReturn->isElementSelected())
        {
            choiceReturn->deselect();
            choiceReturn->setColor(Qt::white);
            choiceConfirm->select();
            choiceConfirm->setColor(Qt::red);
        }
        else if (choiceConfirm->isElementSelected())
        {
            choiceConfirm->deselect();
            choiceConfirm->setColor(Qt::white);
            choiceReturn->select();
            choiceReturn->setColor(Qt::red);
        }
    }

    if (Input::isActionJustPressed(START))
    {
        if (choiceReturn->isElementSelected()) // Return to the main menu
        {
            dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
        }
        else if (choiceConfirm->isElementSelected()) // Player chooses to load the save file
        {
            loadLevel();
        }
    }
}


void Load::draw(QPainter* painter)
{
    // Draw every elements of the GUI list
    std::list<GUIElement*>::iterator it;
    for (it = gui.begin(); it != gui.end(); it++)
    {
        (*it)->draw(painter);
    }
}

void Load::loadLevel()
{
    // Create a new player with the data extracted from the save file
    PlayerCharacter * player = new PlayerCharacter(9.5 * cellSize, 21 * cellSize);
    player->setItsStats(lives, speed, bombNb, bombRange, bombTime, wearArmor);

    switch(level) // Start the level
    {
    case 0:
        dynamic_cast<Widget*>(root)->startLvlFromSave(CHOCHO, player);
        break;

    case 1:
        dynamic_cast<Widget*>(root)->startLvlFromSave(GLAGLA, player);
        break;

    case 2:
        dynamic_cast<Widget*>(root)->startLvlFromSave(JUNGLEDK, player);
        break;

    default:
        break;
    }
}
