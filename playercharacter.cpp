#include "playercharacter.h"


PlayerCharacter::PlayerCharacter(int X, int Y)
    : Entity(X, Y)
{}

void PlayerCharacter::draw(QPainter * aPainter)
{
    aPainter->fillRect(
        QRect(itsX, itsY, 30, 30),
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
    if (event->key() == Qt::Key_Q) { itsMotionX = -1; }
    if (event->key() == Qt::Key_D) { itsMotionX = 1; }
    if (event->key() == Qt::Key_Z) { itsMotionY = -1; }
    if (event->key() == Qt::Key_S) { itsMotionY = 1; }
}


void PlayerCharacter::keyReleasedEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Q) { itsMotionX = 0; }
    if (event->key() == Qt::Key_D) { itsMotionX = 0; }
    if (event->key() == Qt::Key_Z) { itsMotionY = 0; }
    if (event->key() == Qt::Key_S) { itsMotionY = 0; }
}


QRect PlayerCharacter::getRect()
{
    return QRect(itsX, itsY, 30, 30);
}
