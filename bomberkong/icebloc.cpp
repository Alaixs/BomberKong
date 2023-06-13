#include "icebloc.h"
#include "global.h"

IceBloc::IceBloc(int posX, int posY, int endYPos)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_ice_bloc.png");

    animation = new AnimationManager;
    animation->play(0,6);

    timer = 800;

    endY = endYPos;
    isFlying = true;
}

IceBloc::IceBloc(Coordinate pos, int endYPos)
    : Entity(pos.x, pos.y)
{
    sprite.load("://assets/sprites/t_ice_bloc.png");

    animation = new AnimationManager;

    timer = 800;

    endY = endYPos;
    isFlying = true;
}

IceBloc::~IceBloc()
{
    delete animation;
}

void IceBloc::update()
{
    animation->update();
    if(isFlying == true)
    {
        pos.y += 1;
        if(pos.y == endY)
        {
            isFlying = false;
        }
    }
    else
    {
        timer--;
        if(timer == 0)
        {
            deleteEntity();
        }
    }
}


void IceBloc::draw(QPainter * painter)
{
    // Offsets the sprite according to the player character's position (vertical scrolling)
    Coordinate offset = dynamic_cast<Scene*>(parent)->getCameraOffset();
    painter->drawPixmap(
        QRect(pos.x, pos.y - offset.y + 416, cellSize, cellSize),
        sprite,
        QRect(animation->getFrame() * 16, 0, 16, 16)
        );
}

bool IceBloc::getIsFlying()
{
    return isFlying;
}

QRect IceBloc::getRect()
{
     return QRect(pos.x + 3, pos.y + 3, cellSize - 6, cellSize - 4);
}
