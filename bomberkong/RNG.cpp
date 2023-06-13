#include "RNG.h"
#include <ctime>
#include <random>


int RNG::randomInt(int min, int max)
{
    static std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}
