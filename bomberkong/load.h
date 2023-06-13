#ifndef LOAD_H
#define LOAD_H

#include "scene.h"

class Load : public Scene
{

private:


public:
    Load(QWidget* root);

    /**
     * @brief Update the state of every updatable element in this menu
     */
    void update();

    /**
     * @brief Draw the menu
     * @param painter : The QPainter object used to draw the menu
     */
    void draw(QPainter* painter);

};

#endif // LOAD_H
