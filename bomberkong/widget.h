#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <vector>
#include "entity.h"
#include "soundmanager.h"
#include "guielement.h"
#include "scene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

/**
 * @brief The enum of game's state
 */
enum gameState{
    MENU,
    RUNNING,
    PAUSED
};

/**
 * @brief The Widget class, the class to make the window of the game
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Create a Widget
     * @param parent : the parent of the widget
     */
    Widget(QWidget *parent = nullptr);
    /**
     * @brief Destructor of Widget
     */
    ~Widget();

    QTimer timer; ///< Main timer, used to call game ticks

    /**
     * @brief Called when the user presses a key
     *
     * This method is called whenever the user presses a key.
     * It then updates the state of the corresponding key
     *
     * @param ev : the QKeyEvent created by the event in the main class
     */
    void keyPressEvent(QKeyEvent * ev);

    /**
     * @brief Called when the user releases a key
     *
     * This method is called whenever the user releases a key.
     * It then updates the state of the corresponding key
     *
     * @param ev : the QKeyEvent created by the event in the main class
     */
    void keyReleaseEvent(QKeyEvent * ev);

    int currentMap;

    gameState state = MENU;

    /**
     * @brief Create a new explosion
     * @param posX : the x value
     * @param posY : the y value
     */
    void createExplosion(int posX, int posY);

    SoundManager* soundManager;

    /**
     * @brief Switch the actual scene
     * @param sceneType : The type of the scene
     */
    void switchScene(SceneType sceneType);

private:
    Ui::Widget *ui;
    std::list<Entity*> entities; ///< A vector toring all entities active in the game world
    std::list<GUIElement*> gui;
    bool isWin = false;

    Scene* currentScene; ///< The actuel active scene

private slots:
    /**
     * @brief gameUpdate called each tick (frame)
     *
     * Used to update the state of every object at each frame.
     */
    void gameUpdate();

    /**
     * @brief Draw the game inside the widget.
     *
     * Called each tick to draw every entity inside the widget.
     * The oldest entity will be drawn first.
     */
    void paintEvent(QPaintEvent *);

};


#endif // WIDGET_H
