#include "playercharacter.h"

#include "input.h"
#include "wall.h"


PlayerCharacter::PlayerCharacter(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomberman.png");
    animation.play(0, 4);
}


PlayerCharacter::PlayerCharacter(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bomberman.png");
    animation.play(0, 4);
}


void PlayerCharacter::update()
{
    animation.update();

    if (Input::isActionPressed(MOVE_RIGHT)) { motion.x = 1; }
    else if (Input::isActionPressed(MOVE_LEFT)) { motion.x = -1; }
    else { motion.x = 0; }

    if (Input::isActionPressed(MOVE_DOWN)) { motion.y = 1; }
    else if (Input::isActionPressed(MOVE_UP)) { motion.y = -1; }
    else { motion.y = 0; }

    pos += motion * speed;

    if (abs(motion.x) > 0 || abs(motion.y) > 0)
    {
        animation.play(4, 8);
    }
    else
    {
        animation.play(0, 4);
    }
}


void PlayerCharacter::collisionEvent(Entity * body)
{
    if (dynamic_cast<Wall*>(body) != nullptr)
        {
            int distX = pos.x - body->getPos().x;
            int distY = pos.y - body->getPos().y;

            if (abs(distX) > abs(distY))
            {
                pos.x += (distX / abs(distX)) * speed;
            }
            else
            {
                pos.y += (distY / abs(distY)) * speed;
            }
        }
}


void PlayerCharacter::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


QRect PlayerCharacter::getRect()
{
    return QRect(pos.x + 6, pos.y, 35, 48);
}
