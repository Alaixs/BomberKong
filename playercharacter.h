#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H


#include <QPainter>


#include "entity.h"


class PlayerCharacter : public Entity
{

private:
    int itsMotionX = 0;
    int itsMotionY = 0;
    int itsSpeed = 4;

public:
    PlayerCharacter(int X = 0, int Y = 0);



    void update();
    void draw(QPainter * aPainter);

    void keyPressedEvent(QKeyEvent * event);
    void keyReleasedEvent(QKeyEvent * event);

    void collisionEvent(Entity * body);

    QRect getRect();

signals:
    void putBomb(int aPosX, int aPosY);

};

#endif // PLAYERCHARACTER_H
