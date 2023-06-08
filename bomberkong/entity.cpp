#include "entity.h"

#include <iostream>
#include "scene.h"


Entity::Entity(int x, int y) : pos(x, y), active(true)
{

}


Entity::Entity(Coordinate pos) : pos(pos), active(true)
{

}


Entity::~Entity()
{

}


void Entity::setParent(Scene* newParent)
{
    parent = newParent;
}


Coordinate Entity::getPos()
{
    return pos;
}


void Entity::deleteEntity()
{
    active = false;
}


void Entity::draw(QPainter * painter)
{

}


void Entity::collisionEvent(Entity * body)
{

}


QRect Entity::getRect()
{

}


bool Entity::isActive()
{
    return active;
}
