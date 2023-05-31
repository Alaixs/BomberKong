#include "playercharacter.h"

#include "input.h"


PlayerCharacter::PlayerCharacter(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bomberman.png");
}


PlayerCharacter::PlayerCharacter(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bomberman.png");
}


void PlayerCharacter::update()
{
    if (Input::isActionPressed(MOVE_RIGHT)) { motion.x = 1; }
    else if (Input::isActionPressed(MOVE_LEFT)) { motion.x = -1; }
    else { motion.x = 0; }

    if (Input::isActionPressed(MOVE_DOWN)) { motion.y = 1; }
    else if (Input::isActionPressed(MOVE_UP)) { motion.y = -1; }
    else { motion.y = 0; }

    pos += motion * speed;
}


void PlayerCharacter::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(0, 0, 16, 16)
    );
}
