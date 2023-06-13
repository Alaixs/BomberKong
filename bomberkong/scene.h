#ifndef SCENE_H
#define SCENE_H

#include "coordinate.h"
#include <list>
#include <QPainter>
#include <QWidget>

// Enumeration for the different scene types
enum SceneType { MAIN_MENU,
                 OPTIONS,
                 LOAD,
                 TUTORIAL,
                 ORIGINAL,
                 RELOADED,
                 BOMBERLAND,
                 CHOCHO,
                 GLAGLA,
                 JUNGLEDK,
                 WIN_SCREEN,
                 LOOSE_SCREEN,
                 ALTERNATIVE_ENDING};

/**
 * @brief The class of any scene on the game (pause, mainmenu, win, loose, ...)
 */
class Scene
{

protected:
    QWidget* root;
    Coordinate cameraOffset;
    int itsLowerLimit; ///< The scrolling lower limit
    int itsUpperLimit; ///< The scrolling upper limit
    SceneType itsSceneType;

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

    /**
     * @brief Set the scrolling offset limit
     * @param lowerLimit The lower offset limit
     * @param upperLimit The upper offset limit
     */
    void setOffsetLimit(int lowerLimit, int upperLimit);

    /**
     * @brief
     * @return
     */
    Coordinate getCameraOffset();

    /**
     * @brief Getter for the scrolling lower limit
     * @return The scrolling lower limit
     */
    int getItsLowerLimit();

    /**
     * @brief Getter for the scrolling upper limit
     * @return The scrolling upper limit
     */
    int getItsUpperLimit();

    /**
     * @brief Getter for the scene type
     * @return The scene type
     */
    SceneType getItsSceneType();

};

#endif // SCENE_H
