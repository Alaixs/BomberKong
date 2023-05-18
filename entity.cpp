#include "entity.h"

Entity::Entity(int X, int Y)
{
    itsX = X;
    itsY = Y;
}


int Entity::getX() { return itsX; }
int Entity::getY() { return itsY; }

void Entity::keyPressedEvent(QKeyEvent * event){}
void Entity::keyReleasedEvent(QKeyEvent * event){}
QRect Entity::getRect(){}
void Entity::collisionEvent(Entity * body){}
