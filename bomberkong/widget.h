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

    QTimer timer; // Main timer, used to call game ticks

    void keyPressEvent(QKeyEvent * ev);
    void keyReleaseEvent(QKeyEvent * ev);

private:
    Ui::Widget *ui;
    std::vector<Entity*> entities;

private slots:
    /**
     * @brief gameUpdate called each tick (frame)
     *
     * Used to update the state of every object at each frame.
     */
    void gameUpdate();

    void paintEvent(QPaintEvent *);
};
#endif // WIDGET_H
