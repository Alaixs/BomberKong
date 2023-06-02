#ifndef DONKEYKONG_H
#define DONKEYKONG_H
#include "entity.h"

class DonkeyKong : public Entity
{
public:
    DonkeyKong(int posX, int posY);
    DonkeyKong(Coordinate pos);

    void update();
    void draw(QPainter * painter);

    QRect getRect();

private:
    QPixmap sprite;
    int timer=0;
};

#endif // DONKEYKONG_H
