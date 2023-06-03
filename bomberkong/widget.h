#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <vector>

#include "entity.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

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
    int nbLive = 2;

    /**
     * @brief Create an entity, sets it parent to `this` and adds it to the entities list
     * @param entity
     */
    void createEntity(Entity * entity);

    void createExplosion(int posX, int posY);

    void start();

    void deleteEntities();

private:
    Ui::Widget *ui;
    std::list<Entity*> entities; ///< A vector toring all entities active in the game world

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
