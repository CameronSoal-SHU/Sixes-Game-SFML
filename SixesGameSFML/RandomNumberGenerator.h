#pragma once

// Static class desinged to seed and generate random values
static class RandomNumberGenerator {
public:
	static void GenerateSeed();
	static void GenerateSeed(unsigned s);

	static unsigned GenerateRandomUnsigned(int max);
private:
} s_rng;