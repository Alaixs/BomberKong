#include "coordinate.h"
#include <math.h>


Coordinate::Coordinate()
{
    x = 0;
    y = 0;
}


Coordinate::Coordinate(int xVal, int yVal)
{
    x = xVal; // coordinate x
    y = yVal; // coordiante y
}


float Coordinate::length()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}


Coordinate Coordinate::operator+(const Coordinate& c)
{
    int newX = x + c.x;
    int newY = y + c.y;
    return Coordinate(newX, newY);
}


Coordinate Coordinate::operator+=(const Coordinate& c)
{
    x += c.x;
    y += c.y;
    return *this;
}


Coordinate Coordinate::operator-(const Coordinate& c)
{
    int newX = x - c.x;
    int newY = y - c.y;
    return Coordinate(newX, newY);
}


Coordinate Coordinate::operator-=(const Coordinate& c)
{
    x -= c.x;
    y -= c.y;
    return *this;
}


Coordinate Coordinate::operator*(int n)
{
    int newX = x * n;
    int newY = y * n;
    return Coordinate(newX, newY);
}


Coordinate Coordinate::operator*=(int n)
{
    x *= n;
    y *= n;
    return *this;
}


Coordinate Coordinate::operator/(int n)
{
    return Coordinate(x/n, y/n);
}


Coordinate Coordinate::operator/=(int n)
{
    if (n != 0)
    {
        x /= n;
        y /= n;
    }
    return *this;
}


bool operator==(const Coordinate& c1, const Coordinate& c2)
{
    // Checks if the coordinates are equal on both X and Y axis
    return c1.x == c2.x && c1.y == c2.y;
}
