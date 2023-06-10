#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "guielement.h"


class TextLabel : public GUIElement
{

private:
    QString text;
    QFont font;

public:
    TextLabel(int x, int y, QString t);
    void draw(QPainter* painter);

};

#endif // TEXTLABEL_H
