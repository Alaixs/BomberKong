#ifndef INPUT_H
#define INPUT_H


#include <QKeyEvent>
#include <string>


// [Arrow Keys] : Move character
// [Space] : Place bomb


enum Actions {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};


/**
 * @brief The Input class manages and stores the states of every key used in the game.
 *
 * This static class tracks the status of every key used in the game. it is updated at
 * every key event in `widget.cpp` and can be used to know if a given key is pressed or not.
 * It is also used to bind keys to specific actions (movements, placing a bomb, etc.)
 */
class Input
{

public:

    /**
     * @brief Called when the user presses a key
     *
     * This method is called whenever the user presses a key.
     * It then updates the state of the corresponding key
     *
     * @param event the QKeyEvent created by the event in the main class
     */
    static void keyPressedEvent(QKeyEvent * event);

    /**
     * @brief Called when the user releases a key
     *
     * This method is called whenever the user releases a key.
     * It then updates the state of the corresponding key
     *
     * @param event the QKeyEvent created by the event in the main class
     */
    static void keyReleasedEvent(QKeyEvent * event);


    /**
     * @brief Returns the state of the desired input
     *
     * Returns the state of the desired action (true if pressed, false otherwise).
     * This method is used in every script where keyboard inputs are needed.
     * e.g.
     * if (Input::isActionPressed(MOVE_UP))
     * {
     *     // Do stuff...
     * }
     *
     * @param action
     * @return
     */
    static bool isActionPressed(Actions action);

};

#endif // INPUT_H
