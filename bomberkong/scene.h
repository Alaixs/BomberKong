#ifndef SCENE_H
#define SCENE_H

#include "coordinate.h"
#include <list>
#include <QPainter>
#include <QWidget>


/**
 * @brief The class of any scene on the game (pause, mainmenu, win, loose, ...)
 */
class Scene
{

protected:
    QWidget* root;
    Coordinate cameraOffset;

public:
    /**
     * @brief Create a Scene
     * @param widget : the reference of widget class
     */
    Scene(QWidget* widget);

    /**
     * @brief Destructor for a Scene object
     */
    virtual ~Scene();

    /**
     * @brief Update the scene
     */
    virtual void update() = 0;

    /**
     * @brief Display the actual Scene
     * @param painter : the tools to display
     */
    virtual void draw(QPainter* painter) = 0;

    /**
     * @brief setCameraOffset
     * @param offset
     */
    void setCameraOffset(Coordinate offset);

    Coordinate getCameraOffset();

};

#endif // SCENE_H
