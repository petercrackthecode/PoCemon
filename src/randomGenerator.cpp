
#include <cstdlib>

// Returns a random number bewteen 0 and maxValue (default = 255).
int randomGenerator(int maxValue = 255)
{
    int randomNum = rand() % (maxValue + 1);
    return randomNum;
}

