#include "textlabel.h"

#include <QFontDatabase>
#include "global.h"


int gameFont;

TextLabel::TextLabel(int x, int y, QString t)
    : GUIElement(x, y)
{
    text = t;
    QString family = QFontDatabase::applicationFontFamilies(gameFont).at(0);
    font = family;
}


void TextLabel::draw(QPainter* painter)
{
    if (isVisible)
    {
        painter->setFont(font);
        font.setPixelSize(50);
        QRect rect(pos.x, pos.y, 50, 640);
        painter->drawText(QRect(pos.x, pos.y, 640, 50), Qt::AlignCenter, text, &rect);
    }
}
