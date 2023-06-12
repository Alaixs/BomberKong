#include "textlabel.h"

#include <QFontDatabase>
#include <QPainterPath>
#include "global.h"


int gameFont;

TextLabel::TextLabel(int x, int y, int size, QString text, Alignement align)
    : GUIElement(x, y)
{
    textAlign = align;
    fontSize = size;
    labelText = text;
    QString family = QFontDatabase::applicationFontFamilies(gameFont).at(0);
    font = family;
    font.setPixelSize(size);
    textColor = Qt::white;
}


void TextLabel::draw(QPainter* painter)
{
    if (isVisible)
    {
        QPainterPath path;

        // Goofy ahh calcul
        path.addText(pos.x - (labelText.length() * (fontSize * 0.57) / 2) * textAlign, pos.y, font, labelText);

        painter->setPen(QPen(Qt::black, 3));
        painter->setBrush(textColor);

        painter->drawPath(path);
    }
}


void TextLabel::setColor(QBrush color)
{
    textColor = color;
}


void TextLabel::setText(QString text)
{
    labelText = text;
}
