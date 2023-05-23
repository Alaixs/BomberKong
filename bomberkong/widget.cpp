#include "widget.h"
#include "ui_widget.h"

#include "input.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // updates the games every 16ms
    connect(&timer, SIGNAL( timeout() ),
            this, SLOT( gameUpdate() ));
    timer.start(16); // Approx. 60 FPS
}


Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent * ev) { Input::keyPressedEvent(ev); }
void Widget::keyReleaseEvent(QKeyEvent * ev) { Input::keyReleasedEvent(ev); }


void Widget::gameUpdate()
{
    std::vector<Entity*>::iterator it = entities.begin();
    while (it != entities.end())
    {
        (*it)->update();
        it++;
    }
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(
        0, 0, 800, 600,
        QBrush(QColor(216,197,150))
    );

}

