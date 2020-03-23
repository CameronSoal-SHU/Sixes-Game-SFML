#pragma once

// Static class desinged to seed and generate random values
class RandomNumberGenerator {
public:
	static void GenerateSeed();
	static void GenerateSeed(unsigned s);

	static unsigned GenerateRandomInt(int max);
private:
};