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

enum gameState{
    MENU,
    RUNNING,
    PAUSED
};

enum Scenes {
    MAIN_MENU,
    LEVEL1
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QTimer timer; ///< Main timer, used to call game ticks

    void keyPressEvent(QKeyEvent * ev);
    void keyReleaseEvent(QKeyEvent * ev);

    int wMap;

    gameState state = MENU;

    void createExplosion(int posX, int posY);

    SoundManager* soundManager;

    void switchScene(int sceneId);

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
