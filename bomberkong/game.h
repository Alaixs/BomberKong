#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "entity.h"
#include <list>


class Game : public Scene
{

public:
    Game();
    void update();
    void draw(QPainter* painter);
    void createEntity(Entity* entity);
    void win();
    void createExplosion(int posX, int posY);

public:
    std::list<Entity*> entities;

};

#endif // GAME_H
