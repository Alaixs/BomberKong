#ifndef SAVE_H
#define SAVE_H

#include <fstream>
#include "scene.h"
#include "guielement.h"
#include "textlabel.h"
#include "powerup.h"
#include "playercharacter.h"

class Save : public Scene
{

private:
    std::list<GUIElement*> gui;     ///< A list if GUI Elements
    GUIElement * bg;                ///< The background
    std::ofstream itsSaveFile;      ///< The save file
    TextLabel * choiceReturn;       ///< The Return choice text label
    TextLabel * choiceConfirm;      ///< The Confirm choice text label
    PlayerCharacter * itsPlayer;    ///< The player
    int level;                      ///< The level of the save file
    int lives;                      ///< The number of lives the player has
    int speed;                      ///< The number of speed Power-Up the player has
    int bombNb;                     ///< The number of BombNb Power-Up the player has
    int bombRange;                  ///< The number of BombRange Power-Up the player has
    int bombTime;                   ///< The number of BombTime Power-Up the player has
    bool wearArmor;                 ///< Boolean to know if the player was wearing an armor

public:
    /**
     * @brief Create a new Save menu
     * @param widget : the main widget
     * @param levelToSave : The level to save
     * @param player : The player
     */
    Save(QWidget* root, int levelToSave, PlayerCharacter * player);

    /**
     * @brief Destructor for a Save menu
     */
    ~Save();

    /**
     * @brief Change the display of the Power-Up number
     * @param nb : The number of Power-Up
     * @param type : The type of the Power-Up
     * @param x : The x coord
     * @param y : The y coord
     */
    void displayPUNumber(int nb, PowerUpType type, int x, int y);

    /**
     * @brief Update the state of every updatable element in this menu
     */
    void update();

    /**
     * @brief Draw the menu
     * @param painter : The QPainter object used to draw the menu
     */
    void draw(QPainter* painter);

    /**
     * @brief Save the data in a save file
     */
    void saveData();

};

#endif // SAVE_H
