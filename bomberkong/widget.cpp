// includes the necessary header files
#include "widget.h"
#include "ui_widget.h"

#include "input.h"

Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
ui->setupUi(this);

// updates the game every 16ms
connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
timer.start(16); // Approx. 60 FPS
}

Widget::~Widget()
{
delete ui;
}

// Updating the Input class states
void Widget::keyPressEvent(QKeyEvent *ev)
{
Input::keyPressedEvent(ev);
}

void Widget::keyReleaseEvent(QKeyEvent *ev)
{
Input::keyReleasedEvent(ev);
}

void Widget::gameUpdate()
{
std::vector<Entity*>::iterator it = entities.begin();
while (it != entities.end())
{
// TODO: remove the entity if it is inactive
(*it)->update();
it++;
}

// Draw a frame
repaint(0, 0, 800, 600);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Fill the background with a color
    painter.fillRect(
        0, 0, 800, 600,
        QBrush(QColor(216, 197, 150))
    );

    for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
    {
        // Draw the entity
        (*it)->draw(&painter);
    }
}

