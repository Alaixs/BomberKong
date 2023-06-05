#include "input.h"
#include "widget.h"


bool moveUp = false;
bool moveDown = false;
bool moveLeft = false;
bool moveRight = false;
bool placeBomb = false;
bool pushBomb = false;
bool isPaused = false;


void Input::keyPressedEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_Z:
            moveUp = true;
            break;

        case Qt::Key_S:
            moveDown = true;
            break;

        case Qt::Key_Q:
            moveLeft = true;
            break;

        case Qt::Key_D:
            moveRight = true;
            break;

        case Qt::Key_K:
            placeBomb = true;
            break;

        case Qt::Key_L:
            pushBomb = true;
            break;

        case Qt::Key_Escape:
            if(isPaused == false)
            {
                isPaused = true;
                break;
            }
            isPaused = false;
            break;
    }
}


void Input::keyReleasedEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_Z:
            moveUp = false;
            break;

        case Qt::Key_S:
            moveDown = false;
            break;

        case Qt::Key_Q:
            moveLeft = false;
            break;

        case Qt::Key_D:
            moveRight = false;
            break;

        case Qt::Key_K:
            placeBomb = false;
            break;

        case Qt::Key_L:
            pushBomb = false;
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
