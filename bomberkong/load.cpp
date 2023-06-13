#include "load.h"
#include "widget.h"
#include "textlabel.h"
#include "input.h"

Load::Load(QWidget* root)
    : Scene(root)
{
    itsSaveFile.open("../bomberkong/save.bksave");
    if (!itsSaveFile)
    {
        qDebug("Unable to load the save file.");
    }
    else
    {
        itsSaveFile.close();
    }

    // Background
    bg = new GUIElement(Coordinate(0, 0),
                        Coordinate(832, 832),
                        QString("://assets/sprites/t_menu_bg.png")
                        );
    gui.push_back(bg);

    // Text

    gui.push_back(new TextLabel(320, 85, 64, "Load", CENTER));
    gui.push_back(new TextLabel(50, 160, 48, "Level", LEFT));
    gui.push_back(new TextLabel(50, 370, 48, "Life", LEFT));
    gui.push_back(new TextLabel(50, 470, 48, "Power-Up", LEFT));
    gui.push_back(new TextLabel(50, 610, 48, "Armor", LEFT));

    choiceReturn = new TextLabel(100, 750, 48, "Return", LEFT);
    gui.push_back(choiceReturn);
    choiceConfirm = new TextLabel(350, 750, 48, "Confirm", LEFT);
    gui.push_back(choiceConfirm);

    choiceReturn->select();
    choiceReturn->setColor(Qt::red);

    // Life
    int x = 50, y = 380;
    for (int i = 0; i != 3; i++)
    {
        gui.push_back(
            new GUIElement(
                Coordinate(x, y),
                Coordinate(48, 48),
                "://assets/sprites/t_full_heart.png"
                )
            );
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
        // Power up counter
        gui.push_back(new TextLabel(x+20, y+65, 30, "x0", CENTER));
        x += 60;
    }

    GUIElement * armor = new GUIElement(Coordinate(50, 625), Coordinate(48, 48), "://assets/sprites/t_armor.png");
    gui.push_back(armor);
    gui.push_back(new TextLabel(150, 660, 48, "OFF", CENTER));
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

void Load::update()
{
    if (Input::isActionJustPressed(START)) // The player pressed space to start the game
    {
        if (choiceReturn->isElementSelected()) // Return to the main menu
        {
            dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
        }
        /*else if (choiceConfirm->isElementSelected()) // Load the save file

           */
    }
}


void Load::draw(QPainter* painter)
{
    std::list<GUIElement*>::iterator it;
    for (it = gui.begin(); it != gui.end(); it++)
    {
        (*it)->draw(painter);
    }
}
