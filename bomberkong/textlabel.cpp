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

    font = QFontDatabase::applicationFontFamilies(gameFont).at(0);

    font.setPixelSize(size);

    textColor = Qt::white;
}


void TextLabel::draw(QPainter* painter)
{
    if (isVisible)
    {
        QPainterPath path;

        // Adds the text, offseted according to its size and alignement
        path.addText(pos.x - (labelText.length() * (fontSize * 0.57) / 2) * textAlign, pos.y, font, labelText);

        // Sets a black outline
        painter->setPen(QPen(Qt::black, 3));

        // Sets the texts color
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
