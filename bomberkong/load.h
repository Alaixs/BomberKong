#ifndef LOAD_H
#define LOAD_H

#include <fstream>
#include "scene.h"
#include "guielement.h"
#include "textlabel.h"
#include "powerup.h"

class Load : public Scene
{

private:
    std::list<GUIElement*> gui;     ///< A list if GUI Elements
    GUIElement * bg;                ///< The background
    std::ifstream itsSaveFile;      ///< The save file
    TextLabel * choiceReturn;       ///< The Return choice text label
    TextLabel * choiceConfirm;      ///< The Confirm choice text label
    int level;                      ///< The level of the save file
    int lives;                      ///< The number of lives the player has
    int speed;                      ///< The number of speed Power-Up the player has
    int bombNb;                     ///< The number of BombNb Power-Up the player has
    int bombRange;                  ///< The number of BombRange Power-Up the player has
    int bombTime;                   ///< The number of BombTime Power-Up the player has
    bool wearArmor;                 ///< Boolean to know if the player was wearing an armor

public:
    /**
     * @brief Create a new Load menu
     * @param widget : the main widget
     */
    Load(QWidget* root);

    /**
     * @brief Destructor for a Load menu
     */
    ~Load();

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
     * @brief Load the level based on the save file
     */
    void loadLevel();

};

#endif // LOAD_H
