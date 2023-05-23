#include "entity.h"

Entity::Entity(int x, int y) : pos(x, y), isActive(true)
{

}

Entity::Entity(Coordinate pos) : pos(pos), isActive(true)
{

}

void Entity::setParent(QWidget * aParent)
{
    parent = aParent;
}

Coordinate Entity::getPos()
{
    return pos;
}

void Entity::deleteEntity()
{
    isActive = false;
}

void Entity::draw(QPainter * painter)
{

}

void Entity::collisionEvent(Entity* body)
{

}


QRect Entity::getRect()
{

}
