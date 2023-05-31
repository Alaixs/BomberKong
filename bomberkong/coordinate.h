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
    Coordinate();
    Coordinate(int xVal, int yVal);

    Coordinate operator+(const Coordinate& c);
    Coordinate operator+=(const Coordinate& c);

    Coordinate operator-(const Coordinate& c);
    Coordinate operator-=(const Coordinate& c);

    Coordinate operator*(int n);
    Coordinate operator*=(int n);

    Coordinate operator/(int n);
    Coordinate operator/=(int n);

    friend bool operator==(const Coordinate& c1, const Coordinate& c2);

    int x;
    int y;

};

#endif // COORDINATE_H
