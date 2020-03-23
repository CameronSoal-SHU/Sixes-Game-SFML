#include "RandomNumberGenerator.h"

#include <time.h>
#include <random>

void RandomNumberGenerator::GenerateSeed()
{
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	printf_s("Seed Generated: %u\n", seed);
}

void RandomNumberGenerator::GenerateSeed(unsigned seed)
{
	srand(seed);
	printf_s("Seed Generated: %u\n", seed);
}

unsigned RandomNumberGenerator::GenerateRandomInt(int maxValue)
{
	unsigned intGenerated = (rand() % maxValue) + 1;
	printf_s("Integer Generated: %u\n", intGenerated);

	return intGenerated;	// returns value between 0 and maxValue
}