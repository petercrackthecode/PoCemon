/*
 * randomGenerator.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: dungnguyen
 */
#include <time.h>
#include <cstdlib>

int randomGenerator(int toNum)	{
	srand(time(NULL));
	int aRand= rand() % (toNum + 1);
	return aRand;
}


