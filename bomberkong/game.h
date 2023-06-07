#ifndef GAME_H
#define GAME_H

#include "guielement.h"
#include "scene.h"
#include "entity.h"
#include <list>
#include <QWidget>


class Game : public Scene
{

public:
    Game(QWidget* widget);
    void update();
    void draw(QPainter* painter);

    void createEntity(Entity* entity);
    void deleteAllEntity();

    void win();
    void loose();
    void createExplosion(int posX, int posY);
    void restart();

    int wMap;

public:
    std::list<Entity*> entities;
    GUIElement * startLabel;

};

#endif // GAME_H
