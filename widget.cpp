#include "widget.h"
#include "bomb.h"
#include "destructiblewall.h"
#include "playercharacter.h"
#include "ui_widget.h"
#include "wall.h"

#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    PlayerCharacter * player = new PlayerCharacter(128, 128);

    addEntity(player);

    addEntity(new Wall(0, 0));
    addEntity(new Wall(64, 0));
    addEntity(new Wall(128, 0));
    addEntity(new Wall(0, 0));
    addEntity(new Wall(0, 64));
    addEntity(new Wall(0, 128));

    addEntity(new Bomb(128, 128));

    addEntity(new DestructibleWall(192, 128));

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
    entity->itsParent = this;
    entities.push_back(entity);
}


void Widget::gameUpdate()
{
    std::vector<Entity *>::iterator it = entities.begin();
    while (it != entities.end())
    {
        if ((*it)->isMarkedForDeletion())
        {
            std::cout << "ratio aleks" << std::endl;
            it =  entities.erase(it);
        }
        else
        {
            (*it)->update();
            std::vector<Entity *>::iterator it2;
            for (it2 = entities.begin(); it2 != entities.end(); ++it2)
            {
                if ((*it)->getRect().intersects((*it2)->getRect()))
                {
                    if (it != it2) { (*it)->collisionEvent(*it2); }
                }
            }
            ++it;
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


void Widget::spawnBomb(int aPosX, int aPosY)
{
    addEntity(new Bomb(aPosX, aPosY));
}
