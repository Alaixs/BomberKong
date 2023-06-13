#include "load.h"
#include "widget.h"

Load::Load(QWidget* root)
    : Scene(root)
{
    itsSaveFile.open("../bomberkong/save.bksave");
}

void Load::update()
{

}


void Load::draw(QPainter* painter)
{

}
