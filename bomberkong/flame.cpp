#include "flame.h"
#include "global.h"


Flame::Flame(int posX, int posY)
    : Enemy(posX, posY)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    timer = 187;
}


Flame::Flame(Coordinate position)
    : Enemy(position)
{
    animation = new AnimationManager();
    sprite.load("://assets/sprites/t_flame.png");
    animation->play(0, 6);
    timer = 187;
}


Flame::~Flame()
{
    delete animation;
}


void Flame::update()
{
    int random;
    animation->update();
    timer++;
    srand(time(NULL));
    random = rand() % 832;
    while (pos.y < random)
    {
        pos.y += 3;
    }

    // Delete the barrel once it leaves the screen
    if (pos.y > 832)
    {
        deleteEntity();
    }
}


void Flame::draw(QPainter * painter)
{
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
        );
}


QRect Flame::getRect()
{
    return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}
