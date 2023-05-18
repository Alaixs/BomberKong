#ifndef ENTITY_H
#define ENTITY_H


#include <QPainter>
#include <QKeyEvent>
#include <QKeyEvent>


class Entity
{

public:
    Entity(int X, int Y);

    QWidget * itsParent;
    int getX();
    int getY();

    virtual void update() = 0;
    virtual void draw(QPainter * aPainter) = 0;

    virtual void keyPressedEvent(QKeyEvent * event);
    virtual void keyReleasedEvent(QKeyEvent * event);

    virtual void collisionEvent(Entity * body);

    virtual QRect getRect();

    void deleteEntity();
    bool isMarkedForDeletion();



protected:
    int itsX;
    int itsY;


private:
    bool markedForDeletion;


};

#endif // ENTITY_H
