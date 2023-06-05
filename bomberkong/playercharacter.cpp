
#include "playercharacter.h"

#include <QMessageBox>
#include "widget.h"
#include "indestructiblewall.h"
#include "input.h"
#include "wall.h"
#include "bomb.h"
#include "barrel.h"
#include "explosion.h"
#include "soundmanager.h"
#include "global.h"
extern const int cellSize;

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

    if (Input::isActionPressed(MOVE_RIGHT)) { motion.x = 1; flipped = true; footstepsSfx(); }
    else if (Input::isActionPressed(MOVE_LEFT)) { motion.x = -1; flipped = false; footstepsSfx(); }
    else { motion.x = 0; }

    if (Input::isActionPressed(MOVE_DOWN)) { motion.y = 1; footstepsSfx(); }
    else if (Input::isActionPressed(MOVE_UP)) { motion.y = -1; footstepsSfx(); }
    else { motion.y = 0; }

    if(Input::isActionPressed(PLACE_BOMB))
    {
        if(timer < 0)
        {
            Coordinate bombPos(pos);
            bombPos.x = ((bombPos.x + cellSize / 2) / cellSize) * cellSize;
            bombPos.y = ((bombPos.y + cellSize / 2) / cellSize) * cellSize;
            dynamic_cast<Widget*>(parent)->createEntity(new Bomb(bombPos));
            timer = 200;
        }
    }

    if(pos.y > 25 * cellSize){

        QMessageBox * anotherWay = new QMessageBox();
        anotherWay->setFixedSize(500,100);
        anotherWay->setText("You get on another way and decide to let Donkey Kong with Bomber Girl."
                            "You will never see her again.");
        anotherWay->show();
        dynamic_cast<Widget*>(parent)->timer.stop();
    }

    pos += motion * speed;
    if(timer >= -1)
        timer--;

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
    if (dynamic_cast<Barrel*>(body) != nullptr || dynamic_cast<Explosion*>(body) != nullptr){

        if(dynamic_cast<Widget*>(parent)->nbLive == 0)
        {
            QMessageBox * losePopup = new QMessageBox();
            losePopup->setFixedSize(500, 100);
            losePopup->setText("You lose");
            losePopup->show();
            dynamic_cast<Widget*>(parent)->timer.stop();
        }
        //obliger sinon il reetourne au début du niveau
        else{
            pos.x = 456;
            pos.y = 912;
            dynamic_cast<Widget*>(parent)->nbLive--;
            dynamic_cast<Widget*>(parent)->deleteEntities();
            dynamic_cast<Widget*>(parent)->start();
        }
    }
}


void PlayerCharacter::draw(QPainter * painter)
{
    if (!flipped)
    {
        // Draw the normal sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, cellSize, cellSize),
            sprite,
            QRect(animation.getFrame() * 16, 0, 16, 16)
        );
    }
    else
    {
        // Draw the flipped sprite
        painter->drawPixmap(
            QRect(pos.x, pos.y, cellSize, cellSize),
            sprite.transformed(QTransform().scale(-1, 1)),
            QRect((10 - animation.getFrame()) * 16, 0, 16, 16)
        );
    }
}

void PlayerCharacter::footstepsSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_footsteps.wav", 0.5);
}


void PlayerCharacter::loseThemeSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_loseTheme.wav", 0.5);
}

void PlayerCharacter::winThemeSfx()
{
    SoundManager::getInstance().playSound("://assets/sounds/sfx_winTheme.wav", 0.5);
}


QRect PlayerCharacter::getRect()
{
    return QRect(pos.x + 6, pos.y, 35, cellSize);
}
