#ifndef LOAD_H
#define LOAD_H

#include "scene.h"
#include <fstream>

class Load : public Scene
{

private:
    std::ifstream itsSaveFile;

public:
    /**
     * @brief Create a new Load menu
     * @param widget : the main widget
     */
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
