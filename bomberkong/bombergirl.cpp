#include "bombergirl.h"

#include <QTimer>
#include "global.h"


//extern const int cellSize;

BomberGirl::BomberGirl(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bombergirl.png");

    animation = new AnimationManager();
    animation->play(0, 11);
}


BomberGirl::BomberGirl(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bombergirl.png");

    animation = new AnimationManager();
    animation->play(0, 11);
}


BomberGirl::~BomberGirl()
{
    delete animation;
}


void BomberGirl::update()
{
    animation->update();
}


void BomberGirl::draw(QPainter * painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
    );
}


QRect BomberGirl::getRect()
{
    return QRect(pos.x, pos.y, cellSize, cellSize);
}
