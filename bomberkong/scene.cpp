#include "scene.h"


Scene::Scene(QWidget* widget)
{
    root = widget;
    itsLowerLimit = 0;
    itsUpperLimit = 0;
}


Scene::~Scene()
{

}


void Scene::setCameraOffset(Coordinate offset)
{
    cameraOffset = offset;
}

Coordinate Scene::getCameraOffset()
{
    return cameraOffset;
}

void Scene::setOffsetLimit(int lowerLimit, int upperLimit)
{
    itsLowerLimit = lowerLimit;
    itsUpperLimit = upperLimit;
}

int Scene::getItsLowerLimit()
{
    return itsLowerLimit;
}

int Scene::getItsUpperLimit()
{
    return itsUpperLimit;
}
