#include "entity.h"

Entity::Entity(int X, int Y)
{
    itsX = X;
    itsY = Y;
}

void Entity::keyPressedEvent(QKeyEvent * event){}
void Entity::keyReleasedEvent(QKeyEvent * event){}
QRect Entity::getRect(){}
