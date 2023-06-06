#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "guielement.h"

class GameOver : public GUIElement
{

private:
    QPixmap texture;

public:
    GameOver(Coordinate pos);
    void draw(QPainter * painter);
};

#endif // GAMEOVER_H
