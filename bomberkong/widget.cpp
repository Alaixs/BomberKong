// includes the necessary header files
#include "widget.h"

#include "ui_widget.h"
#include <fstream>
#include "input.h"
#include "playercharacter.h"
#include "wall.h"
#include "indestructiblewall.h"
#include "explosion.h"
#include "bombergirl.h"
#include "donkeykong.h"


Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);



    int height = 960;
    int width = 960;
    setFixedSize(width, height);

    srand(time(nullptr));

    // Create level from file
    std::ifstream levelDataFile;
    levelDataFile.open("../bomberkong/assets/maps/test_level.bkmap");

    if (!levelDataFile.is_open())
    {
        qDebug() << "Could not open the file";
    }

    char block;
    int yPos = 0;
    int xPos = 0;
    while (levelDataFile >> block)
    {
        if (block == ';')
        {
            yPos += 48;
            xPos = 0;

        }
        else
        {
            if (block == '2')
            {
                createEntity(new Wall(xPos, yPos));
            }
            else if (block == '1')
            {
                createEntity(new IndestructibleWall(xPos, yPos));
            }
            xPos += 48;
        }
    }

    levelDataFile.close();

    createEntity(new PlayerCharacter(456, 816));

    createEntity(new BomberGirl(456,96));

    createEntity(new DonkeyKong(492,0));


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
    std::list<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        if ((*it)->isActive())
        {
            (*it)->update();

            // Collisions
            std::list<Entity*>::iterator collider;
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
    repaint(0, 0, 1532,1056);
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Fill the background with a color
    painter.fillRect(
        0, 0, 1532, 1056,
        QBrush(QColor(216, 197, 150))
    );

    std::list<Entity*>::iterator it = entities.begin();
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
