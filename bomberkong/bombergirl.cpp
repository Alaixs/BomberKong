#include "bombergirl.h"

#include "playercharacter.h"
#include <QTimer>
#include "qmessagebox.h"
#include "widget.h"


BomberGirl::BomberGirl(int posX, int posY)
    : Entity(posX, posY)
{
    sprite.load("://assets/sprites/t_bombergirl.png");
    animation.play(0, 11);
}


BomberGirl::BomberGirl(Coordinate pos)
    : Entity(pos)
{
    sprite.load("://assets/sprites/t_bombergirl.png");
    animation.play(0, 11);
}


void BomberGirl::update()
{
    animation.update();
}


void BomberGirl::draw(QPainter * painter)
{
    painter->drawPixmap(
        QRect(pos.x, pos.y, 48, 48),
        sprite,
        QRect(animation.getFrame() * 16, 0, 16, 16)
    );
}


void BomberGirl::collisionEvent(Entity * body)
{
    if (dynamic_cast<PlayerCharacter*>(body) != nullptr)
    {
        QMessageBox * winPopup = new QMessageBox();
        winPopup->setFixedSize(500,100);
        winPopup->setText("Congrats, You win");
        winPopup->show();
        dynamic_cast<Widget*>(parent)->timer.stop();
    }
}


QRect BomberGirl::getRect()
{
    return QRect(pos.x, pos.y, 48, 48);
}
