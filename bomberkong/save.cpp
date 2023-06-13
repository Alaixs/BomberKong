#include "save.h"
#include "widget.h"
#include "textlabel.h"
#include "input.h"
#include "powerup.h"
#include "global.h"

Save::Save(QWidget* root, int levelToSave, PlayerCharacter * player)
    : Scene(root)
{
    // Get the data
    itsPlayer = player;
    level = levelToSave;
    lives = itsPlayer->getItsLivesNb();
    speed = itsPlayer->getItsPUNumber(SPEED);
    bombTime = itsPlayer->getItsPUNumber(BOMB_TIME);
    bombRange = itsPlayer->getItsPUNumber(BOMB_RANGE);
    bombNb = itsPlayer->getItsPUNumber(BOMB_NB);
    wearArmor = itsPlayer->getItsPUNumber(ARMOR);

    // Background
    bg = new GUIElement(Coordinate(0, 0),
                        Coordinate(832, 832),
                        QString("://assets/sprites/t_menu_bg.png")
                        );
    gui.push_back(bg);

    // Create all the text labels
    gui.push_back(new TextLabel(320, 75, 64, "Save ?", CENTER));
    gui.push_back(new TextLabel(50, 160, 48, "Level", LEFT));
    gui.push_back(new TextLabel(50, 370, 48, "Life", LEFT));
    gui.push_back(new TextLabel(50, 470, 48, "Power-Up", LEFT));
    gui.push_back(new TextLabel(50, 610, 48, "Armor", LEFT));

    // Choices text labels
    choiceReturn = new TextLabel(60, 750, 48, "Don't save", LEFT);
    gui.push_back(choiceReturn);
    choiceConfirm = new TextLabel(360, 750, 48, "Confirm", LEFT);
    gui.push_back(choiceConfirm);

    // Default selection
    choiceReturn->select();
    choiceReturn->setColor(Qt::red);

    // Life
    int x = 50, y = 380;
    for (int i = -1; i != 2; i++)
    {
        if (i < lives) // The player has more lives than i
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


Save::~Save()
{
    // Loop to delete every elements inside the gui list
    for (std::list<GUIElement*>::iterator it = gui.begin(); it != gui.end(); it++)
    {
        delete (*it); // Delete the current element of the list
    }
    gui.clear();
}


void Save::displayPUNumber(int nb, PowerUpType type, int x, int y)
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


void Save::update()
{
    if (Input::isActionPressed(MOVE_RIGHT) || Input::isActionPressed(MOVE_LEFT))
    {
        qDebug("Faut attendre que isJustPressed soit fait pour droite et gauche lol");
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
        else if (choiceConfirm->isElementSelected()) // Player chooses to save its progress
        {
            saveData();
        }
    }
}


void Save::draw(QPainter* painter)
{
    // Draw every elements of the GUI list
    std::list<GUIElement*>::iterator it;
    for (it = gui.begin(); it != gui.end(); it++)
    {
        (*it)->draw(painter);
    }
}


void Save::saveData()
{
    itsSaveFile.open("../bomberkong/save.bksave"); // Save file
    if (!itsSaveFile)
    {
        qDebug("Unable to open the file.");
    }
    else
    {
        // Write the data inside the .bksave file
        itsSaveFile << level << " " << lives << " " << speed << " " << bombTime << " " << bombRange << " " << bombNb << " " << wearArmor;
        itsSaveFile.close();
    }

    switch(level) // Go to the next level
    {
    case 0:
        dynamic_cast<Widget*>(root)->startLvlFromSave(CHOCHO,itsPlayer);
        break;

    case 1:
        dynamic_cast<Widget*>(root)->startLvlFromSave(GLAGLA,itsPlayer);
        break;

    case 2:
        dynamic_cast<Widget*>(root)->startLvlFromSave(JUNGLEDK,itsPlayer);
        break;

    default:
        break;
    }
}