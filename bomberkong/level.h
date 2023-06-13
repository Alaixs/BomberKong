#ifndef LEVEL_H
#define LEVEL_H
#include "scene.h"

#include <list>
#include <vector>
#include <QWidget>
#include <fstream>
#include <QDebug>

#include "guielement.h"
#include "entity.h"
#include "bombergirl.h"
#include "donkeykong.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "playercharacter.h"
#include "widget.h"
#include "global.h"
#include "powerup.h"

/**
* @brief The main scene for the level
*/
class Level : public Scene
{

protected:
    std::list<Entity*> entities;    ///< A list of the level entites
    std::list<GUIElement*> gui;     ///< A list of the level GUI Elements
    int bombOnScreenNb;             ///< The number on bomb on screen
    PlayerCharacter* itsPlayer;     ///< The player

public:
    GUIElement* pauseLabel;
    std::vector<int> currentMap; // Which map is currently displayed

    /**
    * @brief The main scene for the level
    */
    Level(QWidget* widget);

    /**
     * @brief Destructor of the level
     */
    ~Level();

    /**
     * @brief Update the level's items
     */
    void update();

    /**
     * @brief Display the actual barrel
     * @param painter : the tools to display
     */
    void draw(QPainter* painter);

    /**
     * @brief Adds an entity in the list and sets its `parent` property as itself.
     * @param entity : The entity to create.
     */
    void createEntity(Entity* entity);

    /**
     * @brief Delete all entities
     */
    void deleteAllEntity();

    /**
     * @brief Triggered when the player touches bombergirl.
     *
     * Triggered when the player touches bombergirl, the scene is then switched to
     * the victory screen.
     */
    virtual void win();

    /**
     * @brief Triggered when the player takes damage.
     *
     * Triggered when the player takes damage. the level is restarted if the player
     * have a remaining life, the scene is switched to the game over screen otherwise.
     */
    void loose();

    /**
     * @brief Triggered when the player exits the first level at the bottom.
     */
    void alternative();

    /**
     * @brief Create an explosion in the world.
     * @param posX the X position of the explosion.
     * @param posY the Y position of the explosion.
     */
    void createExplosion(int posX, int posY);

    /**
     * @brief Reset the level and place the player on the spawn point.
     */
    virtual void restart() = 0;

    /**
     * @brief Update the hearts display based on the player lives
     * @param playerLives The number of lives the player currently has
     */
    void updateLivesGUI(int playerLives);

    /**
     * @brief Increment the number of bomb on the screen
     */
    void incrementBombNb();

    /**
     * @brief Decrement the number of bomb on the screen
     */
    void decrementBombNb();

    /**
     * @brief Set the number of bomb on the screen to 0
     */
    void resetBombOnScreenNb();

    /**
     * @brief Getter for the number of bomb on the screen
     * @return The number of bomb on the screen
     */
    int getBombOnScreenNb();

    /**
     * @brief Add the Power-Up GUI to the screen if the level isn't the Original one
    */
    void initPowerUpGUI();

    /**
     * @brief Update the Power-Up display based on the player collected Power-Up
     * @param nb The number of Power-Up the player has collected
     * @param type The type of Power-Up the player has collected
     */
    void updatePowerUpGUI(int nb, PowerUpType type);

    /**
     * @brief Getter for the level entites
     * @return The entities list of the level
     */
    std::list<Entity*> getEntites();

    PlayerCharacter* getItsPlayer();

    bool isPointInWall(Coordinate point);

};

#endif // LEVEL_H
