#ifndef COORDINATE_H
#define COORDINATE_H


/**
 * @brief The Coordinate class, stores a value for both X and Y axis.
 *
 * This Coordinate class stores a value for both the X and Y axis. It is used to
 * represent positions, mouvement, etc.
 */
class Coordinate{

public:
    Coordinate(int x, int y);

    /**
     * @brief set the X value of the coordinates
     * @param val the new value
     */
    void setX(int val);

    /**
     * @brief set the Y value of the coordinates
     * @param val the new value
     */
    void setY(int val);

    /**
     * @brief Getter for the X value
     * @return X
     */
    int getX();

    /**
     * @brief Getter for the Y value
     * @return  Y
     */
    int getY();

private:
    int x;
    int y;

};

#endif // COORDINATE_H
