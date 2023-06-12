#include <QSettings>
#include "input.h"
#include "widget.h"


// The value of the key
int keyMoveUp;
int keyMoveDown;
int keyMoveLeft;
int keyMoveRight;
int keyPlaceBomb;
int keyPushBomb;
int keyStart;

// The state of every input
bool moveUp = false;
bool moveDown = false;
bool moveLeft = false;
bool moveRight = false;
bool placeBomb = false;
bool pushBomb = false;
bool start = false;

//Those inputs are not persistent and are reseted at the end of the tick
bool fl_start = false;
bool fl_down = false;
bool fl_up = false;


// The value of the key that was pressed during this tick
int lastPressedKey = false;


void Input::loadControlsConfig()
{
    QSettings settings("../bomberkong/config.ini", QSettings::IniFormat);

    keyMoveUp = settings.value("Controls/MoveUp").toInt();
    keyMoveDown = settings.value("Controls/MoveDown").toInt();
    keyMoveLeft = settings.value("Controls/MoveLeft").toInt();
    keyMoveRight = settings.value("Controls/MoveRight").toInt();
    keyPlaceBomb = settings.value("Controls/PlaceBomb").toInt();
    keyPushBomb = settings.value("Controls/PushBomb").toInt();
    keyStart = settings.value("Controls/Start").toInt();
}

void Input::keyPressedEvent(QKeyEvent* event)
{
    lastPressedKey = event->key();

    if (event->key() == keyMoveUp)
    {
        moveUp = true;
        fl_up = true;
    }
    else if (event->key() == keyMoveDown)
    {
        moveDown = true;
        fl_down = true;
    }
    else if (event->key() == keyMoveRight)
    {
        moveRight = true;
    }
    else if (event->key() == keyMoveLeft)
    {
        moveLeft = true;
    }
    else if (event->key() == keyPlaceBomb)
    {
        placeBomb = true;
    }
    else if (event->key() == keyPushBomb)
    {
        pushBomb = true;
    }
    else if (event->key() == keyStart)
    {
        fl_start = true;
    }
}


void Input::keyReleasedEvent(QKeyEvent * event)
{
    if (event->key() == keyMoveUp)
    {
        moveUp = false;
        fl_up = false;
    }
    else if (event->key() == keyMoveDown)
    {
        moveDown = false;
        fl_down = false;
    }
    else if (event->key() == keyMoveRight)
    {
        moveRight = false;
    }
    else if (event->key() == keyMoveLeft)
    {
        moveLeft = false;
    }
    else if (event->key() == keyPlaceBomb)
    {
        placeBomb = false;
    }
    else if (event->key() == keyPushBomb)
    {
        pushBomb = false;
    }
    else if (event->key() == keyStart)
    {
        fl_start = false;
    }
}


bool Input::isActionPressed(Actions action)
{
    switch (action)
    {
        case MOVE_UP:
            return moveUp;
            break;

        case MOVE_DOWN:
            return moveDown;
            break;

        case MOVE_LEFT:
            return moveLeft;
            break;

        case MOVE_RIGHT:
            return moveRight;
            break;

        case PLACE_BOMB:
            return placeBomb;
            break;

        case PUSH_BOMB:
            return pushBomb;
            break;

        default:
            return false;
            break;
    }
}


bool Input::isActionJustPressed(Actions action)
{
    switch (action)
    {
        case START:
            return fl_start;
            break;

        case MOVE_UP:
            return fl_up;
            break;

        case MOVE_DOWN:
            return fl_down;
            break;

        default:
            return false;
            break;
    }
}


void Input::resetFLInputs()
{
    fl_start = false;
    fl_up = false;
    fl_down = false;

    lastPressedKey = 0;
}


int Input::getPressedKey()
{
    return lastPressedKey;
}
