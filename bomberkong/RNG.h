#ifndef RNG_H
#define RNG_H


class RNG
{

public:
    /**
     * @brief Retruns a random int in a range
     * @param min : The minimum value (inclusive)
     * @param max : The maximum value (inclusive)
     * @return A random int
     */
    static int randomInt(int min, int max);

};

#endif // RNG_H
