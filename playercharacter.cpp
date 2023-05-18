#include <iostream>

#include "playercharacter.h"
#include "wall.h"


PlayerCharacter::PlayerCharacter(int X, int Y)
    : Entity(X, Y)
{}


void PlayerCharacter::draw(QPainter * aPainter)
{
    aPainter->fillRect(
        QRect(itsX, itsY, 64, 64),
        QBrush(QColor(232, 115, 73))
    );
}


void PlayerCharacter::update()
{
    itsX += itsMotionX * itsSpeed;
    itsY += itsMotionY * itsSpeed;
}


void PlayerCharacter::keyPressedEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_A) { itsMotionX = -1; }
    if (event->key() == Qt::Key_D) { itsMotionX = 1; }
    if (event->key() == Qt::Key_W) { itsMotionY = -1; }
    if (event->key() == Qt::Key_S) { itsMotionY = 1; }
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
    if (dynamic_cast<Wall*>(body) != nullptr)
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
