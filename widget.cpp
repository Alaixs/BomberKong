#include "widget.h"
#include "playercharacter.h"
#include "wall.h"
#include "ui_widget.h"

#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    addEntity(new PlayerCharacter);
    Wall * w = new Wall(100, 100);
    addEntity(w);

    connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));

    timer.start(16);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(
        QRect(0, 0, 800, 600),
        QBrush(QColor(255, 255, 255))
    );

    std::vector<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->draw(&painter);
    }
}


void Widget::addEntity(Entity * entity)
{
    entities.push_back(entity);
}


void Widget::gameUpdate()
{
    std::vector<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->update();
        std::vector<Entity *>::iterator it2;
        for (it2 = entities.begin(); it2 != entities.end(); ++it2)
        {
            if ((*it)->getRect().intersects((*it2)->getRect()))
            {
                if (it != it2) { std::cout << "bonk" << std::endl; };
            }
        }
    }
    repaint(0, 0, 800, 600);
}

void Widget::keyPressEvent(QKeyEvent * event)
{
    std::vector<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->keyPressedEvent(event);
    }
}

void Widget::keyReleaseEvent(QKeyEvent * event)
{
    std::vector<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->keyReleasedEvent(event);
    }
}
