#include "gameover.h"

GameOver::GameOver(Coordinate position)
    : GUIElement(position)
{
    texture.load("://assets/sprites/t_game_over.png");
}


void GameOver::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 483, 212),
        texture
        );
}
