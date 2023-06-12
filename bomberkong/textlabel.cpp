#include "textlabel.h"

#include <QFontDatabase>
#include <QPainterPath>
#include "global.h"


int gameFont;

TextLabel::TextLabel(int x, int y, int size, QString t, Alignement alignement)
    : GUIElement(x, y)
{
    textAlign = alignement;
    fontSize = size;
    text = t;
    QString family = QFontDatabase::applicationFontFamilies(gameFont).at(0);
    font = family;
    font.setPixelSize(size);
}


void TextLabel::draw(QPainter* painter)
{
    if (isVisible)
    {
        QPainterPath path;

        // Goofy ahh calcul
        path.addText(pos.x - (text.length() * (fontSize * 0.57 ) / 2) * textAlign, pos.y, font, text);

        painter->setPen(QPen(Qt::black, 3));
        painter->setBrush(Qt::white);

        painter->drawPath(path);
    }
}
