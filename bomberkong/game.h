#ifndef GAME_H
#define GAME_H

#include "guielement.h"
#include "scene.h"
#include "entity.h"
#include <list>
#include <QWidget>

/**
* @brief The main scene for the level
*/
class Game : public Scene
{
protected:
    std::list<Entity*> entities;
    std::list<GUIElement*> gui;

public:
    GUIElement* pauseLabel;
    int wMap;

    /**
    * @brief The main scene for the level
    */
    Game(QWidget* widget);
    ~Game();

    void update();
    void draw(QPainter* painter);

    void createEntity(Entity* entity);
    void deleteAllEntity();

    void win();
    void loose();
    void alternative();
    void createExplosion(int posX, int posY);
    void restart();

};

#endif // GAME_H
