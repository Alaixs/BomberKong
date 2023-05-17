#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QKeyEvent>
#include <QKeyEvent>

class Entity
{

public:
    Entity(int X, int Y);

    int getX();
    int getY();

    virtual void update() = 0;
    virtual void draw(QPainter * aPainter) = 0;
    virtual void keyPressedEvent(QKeyEvent * event);
    virtual void keyReleasedEvent(QKeyEvent * event);
    virtual QRect getRect();


protected:
    int itsX;
    int itsY;

};

#endif // ENTITY_H
