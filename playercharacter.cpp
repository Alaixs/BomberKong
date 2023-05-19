#include <iostream>

#include "destructiblewall.h"
#include "playercharacter.h"

#include "qwidget.h"
#include "wall.h"
#include "widget.h"


PlayerCharacter::PlayerCharacter(int X, int Y)
    : Entity(X, Y)
{}


void PlayerCharacter::draw(QPainter * aPainter)
{
    QPixmap sprite(":/assets/t_bomberman.png");
    aPainter->drawPixmap(
        QRect(itsX, itsY, 64, 64),
        sprite
    );
}


void PlayerCharacter::update()
{
    itsX += itsMotionX * itsSpeed;
    itsY += itsMotionY * itsSpeed;

}


void PlayerCharacter::keyPressedEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_A) { itsMotionX = -1; dynamic_cast<Widget*>(itsParent)->playWalkSound(); }
    if (event->key() == Qt::Key_D) { itsMotionX = 1; dynamic_cast<Widget*>(itsParent)->playWalkSound();}
    if (event->key() == Qt::Key_W) { itsMotionY = -1; dynamic_cast<Widget*>(itsParent)->playWalkSound();}
    if (event->key() == Qt::Key_S) { itsMotionY = 1; dynamic_cast<Widget*>(itsParent)->playWalkSound();}

    if (event->key() == Qt::Key_Space) { dynamic_cast<Widget*>(itsParent)->spawnBomb(itsX, itsY); }
}


void PlayerCharacter::keyReleasedEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_A) { itsMotionX = 0; }
    if (event->key() == Qt::Key_D) { itsMotionX = 0; }
    if (event->key() == Qt::Key_W) { itsMotionY = 0; }
    if (event->key() == Qt::Key_S) { itsMotionY = 0; }
}


void PlayerCharacter::collisionEvent(Entity * body)
{
    if (dynamic_cast<Wall*>(body) != nullptr || dynamic_cast<DestructibleWall*>(body) != nullptr)
    {
        int distX = itsX - body->getX();
        int distY = itsY - body->getY();

        if (abs(distX) > abs(distY))
        {
            itsX += (distX / abs(distX)) * itsSpeed;
        }
        else
        {
            itsY += (distY / abs(distY)) * itsSpeed;
        }
    }
}


QRect PlayerCharacter::getRect()
{
    return QRect(itsX, itsY, 64, 64);
}
