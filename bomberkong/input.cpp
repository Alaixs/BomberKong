#include "input.h"
#include "widget.h"


bool moveUp = false;
bool moveDown = false;
bool moveLeft = false;
bool moveRight = false;
bool placeBomb = false;
bool pushBomb = false;
bool start = false;

bool fl_start = false; // FL = Frame limited
bool isPaused = true;


void Input::keyPressedEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_Up:
            moveUp = true;
            break;

        case Qt::Key_Down:
            moveDown = true;
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

        case PAUSE:
            return isPaused;
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
    }
}


void Input::resetFLInputs()
{
    fl_start = false;
}
