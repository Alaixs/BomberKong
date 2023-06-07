#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <QPainter>
#include <QWidget>


/**
 * @brief The class of any scene on the game (pause, mainmenu, win, loose, ...)
 */
class Scene
{

public:
    /**
     * @brief Create a Scene
     * @param widget : the reference of widget class
     */
    Scene(QWidget* widget);


    /**
     * @brief Update the scene
     */
    virtual void update() = 0;

    /**
     * @brief Display the actual Scene
     * @param painter : the tools to display
     */
    virtual void draw(QPainter* painter) = 0;

protected:
    QWidget* root;

//protected:
    //std::list<Entity*> entities;

};

#endif // SCENE_H
