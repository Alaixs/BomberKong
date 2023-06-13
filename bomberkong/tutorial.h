#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "guielement.h"
#include "scene.h"
#include "entity.h"
#include "level.h"
#include <list>
#include <QWidget>


/**
 * @brief The class of tutorial screen
 */
class Tutorial : public Level
{

public:
    GUIElement * startLabel;
    int currentMap;

    /**
     * @brief Create new Tutorial screen
     * @param widget : the widget of the game
     */
    Tutorial(QWidget* widget);

    /**
     * @brief Destructor of Tutorial
     */
    ~Tutorial();

    /**
     * @brief Update Tutorial screen (position, sprite, etc)
     */
    void update();

    /**
     * @brief Create new entity on Tutorial screen
     * @param entity : the entity to be added
     */
    void createEntity(Entity* entity);

    /**
     * @brief Delete all entities on Tutorial screen
     */
    void deleteAllEntity();

    /**
     * @brief Switch to win menu
     */
    void win();

    /**
     * @brief Switch to loose menu
     */
    void loose();

    /**
     * @brief Switch to alternative win menu
     */
    void alternative();

    /**
     * @brief Create new explosion
     * @param posX : the x value
     * @param posY : the y value
     */
    void createExplosion(int posX, int posY);

    /**
     * @brief Reload the Tutorial menu
     */
    void restart();

    /**
     * @brief Switch scene to the next level
     */
    void nextLvl();

};

#endif // TUTORIAL_H
