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
    int x;
    int y;

    /**
     * @brief Create new coordinate with 0,0 by default
     */
    Coordinate();

    /**
     * @brief Calculates the amplitude of the vector
     * @return The amplitude of the vector
     */
    float length();

    /**
     * @brief Create new coordinate with entry
     * @param xVal : the x value
     * @param yVal : the y value
     */
    Coordinate(int xVal, int yVal);


    /**
     * @brief Operator + overloading
     * @param c : the coordinate to add
     * @return Coordinate result on addition
     */
    Coordinate operator+(const Coordinate& c);

    /**
     * @brief Operator += overloading
     * @param c : the coordinate to add
     * @return Coordinate after addition
     */
    Coordinate operator+=(const Coordinate& c);


    /**
     * @brief Operator - overloading
     * @param c : the coordinate to substract
     * @return Coordinate result on substraction
     */
    Coordinate operator-(const Coordinate& c);

    /**
     * @brief Operator -= overloading
     * @param c : the coordinate to substract
     * @return Coordinate after substraction
     */
    Coordinate operator-=(const Coordinate& c);


    /**
     * @brief Operator * overloading
     * @param n : the multiplier
     * @return Coordinate result on multiplication
     */
    Coordinate operator*(int n);

    /**
     * @brief Operator *= overloading
     * @param n : the multiplier
     * @return Coordinate after multiplication
     */
    Coordinate operator*=(int n);


    /**
     * @brief Operator / overloading
     * @param n : the divider
     * @return Coordinate result on division
     */
    Coordinate operator/(int n);

    /**
     * @brief Operator /= overloading
     * @param n : the divider
     * @return Coordinate after division
     */
    Coordinate operator/=(int n);


    /**
     * @brief Operator == overloading
     * @param c1 : the first coordinate
     * @param c2 : the second coordinate
     * @return if c1 and c2 have same value on x and y
     */
    friend bool operator==(const Coordinate& c1, const Coordinate& c2);

};

#endif // COORDINATE_H
