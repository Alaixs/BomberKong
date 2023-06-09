#ifndef LEVEL_H
#define LEVEL_H

#include "guielement.h"
#include "scene.h"
#include "entity.h"
#include <list>
#include <vector>
#include <QWidget>


/**
* @brief The main scene for the level
*/
class Level : public Scene
{

protected:
    std::list<Entity*> entities;
    std::list<GUIElement*> gui;

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
    void win();

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
    void restart();

    /**
     * @brief Update the hearts display based on the player lives
     * @param playerLives The number of lives the player currently has
     */
    void updateLivesGUI(int playerLives);

};

#endif // LEVEL_H
