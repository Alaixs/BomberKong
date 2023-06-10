#include "input.h"
#include "widget.h"


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


void Input::keyPressedEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_Up:
            moveUp = true;
            fl_up = true;
            break;

        case Qt::Key_Down:
            moveDown = true;
            fl_down = true;
            break;

        case Qt::Key_Left:
            moveLeft = true;
            break;

        case Qt::Key_Right:
            moveRight = true;
            break;

        case Qt::Key_W:
            placeBomb = true;
            break;

        case Qt::Key_X:
            pushBomb = true;
            break;

        case Qt::Key_Space:
            fl_start = true;
            break;
    }
}


void Input::keyReleasedEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_Up:
            moveUp = false;
            break;

        case Qt::Key_Down:
            moveDown = false;
            break;

        case Qt::Key_Left:
            moveLeft = false;
            break;

        case Qt::Key_Right:
            moveRight = false;
            break;

        case Qt::Key_W:
            placeBomb = false;
            break;

        case Qt::Key_X:
            pushBomb = false;
            break;

        case Qt::Key_Space:
            fl_start = false;
            break;
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
}
