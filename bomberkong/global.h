#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

using namespace std;


// define the cell size
// define here to allow all other class to get this
extern int cellSize;

extern bool isPaused;

enum CURRENT_LVL { TUTORIAL, ORIGINAL, RELOADED }; // Enumeration for the different levels

extern CURRENT_LVL currentLevel;

#endif // GLOBAL_H
