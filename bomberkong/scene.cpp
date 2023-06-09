#include "scene.h"


Scene::Scene(QWidget* widget)
{
    root = widget;
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
