
#include "dummy.h"

#include "global.h"
#include "soundmanager.h"

//extern const int cellSize;

Dummy::Dummy(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomberman.png");
    animation.play(0, 4);
    timer = 0;
}


Dummy::Dummy(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bomberman.png");
    animation.play(0, 4);
    timer = 0;;
}

Character::~Character()
{
    qDebug() << "Destructeur Character appelé";
}

void Dummy::update()
{
    animation.update();
}


void Dummy::draw(QPainter * painter)
{

    // Draw the normal sprite
    painter->drawPixmap(
        QRect(pos.x, pos.y, cellSize, cellSize),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
        );

}


void Dummy::loseThemeSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_loseTheme.wav", 0.5);
}

QRect Dummy::getRect()
{
    return QRect(pos.x + 6, pos.y, 35, cellSize);
}
