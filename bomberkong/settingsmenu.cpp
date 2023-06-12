#include "settingsmenu.h"

#include <QSettings>
#include "widget.h"
#include "input.h"


SettingsMenu::SettingsMenu(QWidget* root)
    : Scene(root)
{
    // Background
    bg = new GUIElement(Coordinate(0, 0),
                        Coordinate(832, 832),
                        QString("://assets/sprites/t_menu_bg.png")
                        );

    windowTitle = new TextLabel(50, 100, 55, "SETTINGS");

    labelMoveUp = new TextLabel(70, 200, 35, "MOVE UP");
    labelMoveDown = new TextLabel(70, 250, 35, "MOVE DOWN");
    labelMoveRight = new TextLabel(70, 300, 35, "MOVE RIGHT");
    labelMoveLeft = new TextLabel(70, 350, 35, "MOVE LEFT");
    labelPlaceBomb = new TextLabel(70, 400, 35, "PLACE BOMB");
    labelPushBomb = new TextLabel(70, 450, 35, "PUSH BOMB");
    labelStart = new TextLabel(70, 500, 35, "START");
    labelReset = new TextLabel(70, 600, 35, "RESET");
    labelBack = new TextLabel(70, 750, 35, "< BACK");

    options.push_back(labelMoveUp);
    options.push_back(labelMoveDown);
    options.push_back(labelMoveRight);
    options.push_back(labelMoveLeft);
    options.push_back(labelPlaceBomb);
    options.push_back(labelPushBomb);
    options.push_back(labelStart);
    options.push_back(labelReset);
    options.push_back(labelBack);

    currentSelectedOption = 0;
    options.at(currentSelectedOption)->setColor(Qt::red);
}


void SettingsMenu::update()
{
    if (Input::isActionJustPressed(MOVE_DOWN))
    {
        options.at(currentSelectedOption)->setColor(Qt::white);

        currentSelectedOption++;
        if (currentSelectedOption == 9)
        {
            currentSelectedOption = 0;
        }

        options.at(currentSelectedOption)->setColor(Qt::red);
    }

    if (Input::isActionJustPressed(MOVE_UP))
    {
        options.at(currentSelectedOption)->setColor(Qt::white);

        currentSelectedOption--;
        if (currentSelectedOption == -1)
        {
            currentSelectedOption = 8;
        }

        options.at(currentSelectedOption)->setColor(Qt::red);
    }

    if (waitingForInput)
    {
        int key = Input::getPressedKey();
        if (key != 0)
        {
            QSettings settings("../bomberkong/config.ini", QSettings::IniFormat);

            switch (currentSelectedOption)
            {
                case 0:
                    settings.setValue("Controls/MoveUp", key);
                    break;

                case 1:
                    settings.setValue("Controls/MoveDown", key);
                    break;

                case 2:
                    settings.setValue("Controls/MoveRight", key);
                    break;

                case 3:
                    settings.setValue("Controls/MoveLeft", key);
                    break;

                case 4:
                    settings.setValue("Controls/PlaceBomb", key);
                    break;

                case 5:
                    settings.setValue("Controls/PushBomb", key);
                    break;

                case 6:
                    settings.setValue("Controls/Start", key);
                    break;
            }

            Input::loadControlsConfig();
            options.at(currentSelectedOption)->setColor(Qt::red);
            waitingForInput = false;
        }
    }

    if (Input::isActionJustPressed(START))
    {
        if (currentSelectedOption == 8)
        {
            dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
        }
        else if (currentSelectedOption == 7)
        {
            QSettings settings("../bomberkong/config.ini", QSettings::IniFormat);

            settings.setValue("Controls/MoveUp", 16777235);
            settings.setValue("Controls/MoveDown", 16777237);
            settings.setValue("Controls/MoveLeft", 16777234);
            settings.setValue("Controls/MoveRight", 16777236);
            settings.setValue("Controls/PlaceBomb", 87);
            settings.setValue("Controls/PushBomb", 88);
            settings.setValue("Controls/Start", 32);

            Input::loadControlsConfig();
        }
        else
        {
            qDebug() << currentSelectedOption;
            waitingForInput = true;
            options.at(currentSelectedOption)->setColor(Qt::green);
        }
    }
}


void SettingsMenu::draw(QPainter* painter)
{
    bg->draw(painter);
    windowTitle->draw(painter);

    std::vector<TextLabel*>::iterator it;
    for (it = options.begin(); it != options.end(); ++it)
    {
        (*it)->draw(painter);
    }

    //labelBack->draw(painter);
}
