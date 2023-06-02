// includes the necessary header files
#include "widget.h"
#include "ui_widget.h"

#include "input.h"

#include "playercharacter.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "bomb.h"
#include "explosion.h"
#include "bombergirl.h"

Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

    createEntity(new PlayerCharacter(200, 200));



    createEntity(new Wall(0, 0));
    createEntity(new Wall(48, 0));
    createEntity(new Wall(0, 48));

    createEntity(new IndestructibleWall(200, 48));

    createEntity(new BomberGirl(300,300));


    // updates the game every 16ms
    connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    timer.start(16);
}


Widget::~Widget()
{
    delete ui;
}


// Updating the Input class states
void Widget::keyPressEvent(QKeyEvent *ev)
{
    Input::keyPressedEvent(ev);
}


void Widget::keyReleaseEvent(QKeyEvent *ev)
{
    Input::keyReleasedEvent(ev);
}


void Widget::gameUpdate()
{
    std::vector<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        if ((*it)->isActive())
        {
            (*it)->update();

            // Collisions
            std::vector<Entity*>::iterator collider;
            for (collider = entities.begin(); collider != entities.end(); ++collider)
            {
                if (it != collider)
                {
                    if ((*it)->getRect().intersects((*collider)->getRect()))
                    {
                        (*it)->collisionEvent(*collider);
                    }
                }
            }

            ++it;
        }
        else
        {
            //delete *it;
            it = entities.erase(it);
        }
    }

    // Draw a frame
    repaint(0, 0, 800, 600);
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Fill the background with a color
    painter.fillRect(
        0, 0, 800, 600,
        QBrush(QColor(216, 197, 150))
    );

    std::vector<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        // Draw the entity
        (*it)->draw(&painter);
        it++;
    }
}


void Widget::createEntity(Entity * entity)
{
    entities.push_back(entity);
    entity->setParent(this);
}


void Widget::createExplosion(int posX, int posY)
{
    createEntity(new Explosion(posX, posY));
}
