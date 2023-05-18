#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
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

    void paintEvent(QPaintEvent *);
    void addEntity(Entity * entity);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    void spawnBomb(int aPosX, int aPosY);
    void spawnExplosion(int aPosX, int aPosY);


private:
    Ui::Widget *ui;

    QPixmap map;
    QPainter * painter = new QPainter(&map);

    QTimer timer;

    std::vector<Entity*> entities;

private slots:
    void gameUpdate();

};
#endif // WIDGET_H
