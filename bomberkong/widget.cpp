// includes the necessary header files
#include "widget.h"

#include "ui_widget.h"

#include "input.h"
#include "playercharacter.h"
#include "indestructiblewall.h"
#include "explosion.h"
#include "bombergirl.h"
#include "donkeykong.h"


Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);



    int height = 1056;
    int width = 1532;
    setFixedSize(width, height);

    srand(time(nullptr));

    for(int h=0;h<21;h++){
        for(int l=0;l<32;l++){
            if(h == 0 || h == 20 || l == 0 || l == 31){
                createEntity(new IndestructibleWall(48*l,48*h+48));
            }
        }
    }

    createEntity(new PlayerCharacter(716, 912));

    createEntity(new BomberGirl(716,144));

    createEntity(new DonkeyKong(716,0));


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
