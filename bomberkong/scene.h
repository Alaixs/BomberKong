#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <QPainter>
#include <QWidget>


class Scene
{

public:
    Scene();

    virtual void update() = 0;
    virtual void draw(QPainter* painter) = 0;

private:
    QWidget* root;

//protected:
//    std::list<Entity*> entities;

};

#endif // SCENE_H
