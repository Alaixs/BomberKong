#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <QPainter>
#include <QWidget>


class Scene
{

public:
    Scene(QWidget* widget);

    virtual void update() = 0;
    virtual void draw(QPainter* painter) = 0;

protected:
    QWidget* root;

//protected:
    //std::list<Entity*> entities;

};

#endif // SCENE_H
