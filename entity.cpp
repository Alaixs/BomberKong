#include "entity.h"

Entity::Entity(int X, int Y)
{
    itsX = X;
    itsY = Y;
    markedForDeletion = false;
}



int Entity::getX() { return itsX; }
int Entity::getY() { return itsY; }

void Entity::keyPressedEvent(QKeyEvent * event){}
void Entity::keyReleasedEvent(QKeyEvent * event){}
QRect Entity::getRect(){}
void Entity::collisionEvent(Entity * body){}


void Entity::deleteEntity()
{
    markedForDeletion = true;
}

bool Entity::isMarkedForDeletion()
{
    return markedForDeletion;
}
