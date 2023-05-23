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
    // Update
}
