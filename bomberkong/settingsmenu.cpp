#include "settingsmenu.h"

#include <QSettings>
#include "widget.h"
#include "input.h"


SettingsMenu::SettingsMenu(QWidget* root)
    : Scene(root)
{
    windowTitle = new TextLabel(10, 100, 35, "SETTINGS");

    labelMoveUp = new TextLabel(10, 200, 35, "MOVE UP");
    labelMoveDown = new TextLabel(10, 250, 35, "MOVE DOWN");
    labelMoveRight = new TextLabel(10, 300, 35, "MOVE RIGHT");
    labelMoveLeft = new TextLabel(10, 350, 35, "MOVE LEFT");
    labelPlaceBomb = new TextLabel(10, 400, 35, "PLACE BOMB");
    labelPushBomb = new TextLabel(10, 450, 35, "PUSH BOMB");
    labelStart = new TextLabel(10, 500, 35, "START");
    labelBack = new TextLabel(10, 700, 35, "< BACK");

    options.push_back(labelMoveUp);
    options.push_back(labelMoveDown);
    options.push_back(labelMoveRight);
    options.push_back(labelMoveLeft);
    options.push_back(labelPlaceBomb);
    options.push_back(labelPushBomb);
    options.push_back(labelStart);
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
        if (currentSelectedOption == 8)
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
            currentSelectedOption = 7;
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
        if (currentSelectedOption == 7)
        {
            dynamic_cast<Widget*>(root)->switchScene(MAIN_MENU);
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
    windowTitle->draw(painter);

    std::vector<TextLabel*>::iterator it;
    for (it = options.begin(); it != options.end(); ++it)
    {
        (*it)->draw(painter);
    }

    //labelBack->draw(painter);
}
