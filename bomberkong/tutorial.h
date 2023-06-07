#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "guielement.h"
#include "scene.h"
#include "entity.h"
#include "game.h"
#include <list>
#include <QWidget>


class Tutorial : public Game
{

public:
    Tutorial(QWidget* widget);
    ~Tutorial();

    void update();
    void draw(QPainter* painter);

    void createEntity(Entity* entity);
    void deleteAllEntity();

    void win();
    void loose();
    void alternative();
    void createExplosion(int posX, int posY);
    void restart();

    int wMap;

public:
    //std::list<Entity*> entities;
    GUIElement * startLabel;

};

#endif // TUTORIAL_H
