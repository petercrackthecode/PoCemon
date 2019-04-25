
#include <cstdlib>

// Returns a random number bewteen minValue and maxValue (inclusive).
// Default is between 0 and 255.
int randomGenerator(int minValue = 0, int maxValue = 255)
{
    int randomNum = rand() % (maxValue - minValue + 1) + minValue;
    return randomNum;
}

