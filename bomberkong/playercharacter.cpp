#include <QMessageBox>

#include "playercharacter.h"

#include "widget.h"
#include "indestructiblewall.h"
#include "input.h"
#include "wall.h"
#include "bomb.h"
#include "tonneaux.h"
#include "explosion.h"

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

    if (Input::isActionPressed(MOVE_RIGHT)) { motion.x = 1; flipped = true; }
    else if (Input::isActionPressed(MOVE_LEFT)) { motion.x = -1; flipped = false; }
    else { motion.x = 0; }

    if (Input::isActionPressed(MOVE_DOWN)) { motion.y = 1; }
    else if (Input::isActionPressed(MOVE_UP)) { motion.y = -1; }
    else { motion.y = 0; }

    if(timer<0){
        if(Input::isActionPressed(PLACE_BOMB)) {
            Coordinate bombPos(pos);
            bombPos.x = ((bombPos.x + 48/2) / 48) * 48;
            bombPos.y = ((bombPos.y + 48/2) / 48) * 48;
            dynamic_cast<Widget*>(parent)->createEntity(new Bomb(bombPos));
            timer=200;
        }
    }

    pos += motion * speed;
    if(timer>=-1){
        timer--;}
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
    if (dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<IndestructibleWall*>(body) != nullptr)
    {
        // Offsets the player away from the collider
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
    if (dynamic_cast<Tonneaux*>(body) != nullptr || dynamic_cast<Explosion*>(body) != nullptr){
        if(nbLive == 0)
        {
            QMessageBox * losePopup = new QMessageBox();
            losePopup->setFixedSize(500,100);
            losePopup->setText("You lose");
            losePopup->show();
            dynamic_cast<Widget*>(parent)->timer.stop();
        }
        //obliger sinon il reetourne au début du niveau
        else{
            pos.x=716;
            pos.y=912;
            nbLive--;
        }
    }

}


void PlayerCharacter::draw(QPainter * painter)
{
    if (!flipped)
    {
        // Draw the normal sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, 48, 48),
            sprite,
            QRect(animation.getFrame() * 16, 0, 16, 16)
        );
    }
    else
    {
        // Draw the flipped sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, 48, 48),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((10 - animation.getFrame()) * 16, 0, 16, 16)
        );
    }
}


QRect PlayerCharacter::getRect()
{
    return QRect(pos.x + 6, pos.y, 35, 48);
}
