#ifndef LOAD_H
#define LOAD_H

#include <fstream>
#include "scene.h"
#include "guielement.h"
#include "textlabel.h"

class Load : public Scene
{

private:
    std::list<GUIElement*> gui;

    GUIElement * bg;
    std::ifstream itsSaveFile;
    TextLabel * choiceReturn;
    TextLabel * choiceConfirm;

public:
    /**
     * @brief Create a new Load menu
     * @param widget : the main widget
     */
    Load(QWidget* root);

    /**
     * @brief Destructor for a Load menu
     */
    ~Load();

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
