#pragma once
#include "SFML/Graphics.hpp"
#include <string>

// Static class to handle receiving and validating input
static class IOHandler
{
public:
	// Functions used to limit inputs
	static void NumericInput();
	static void AlphaInput();
	static void AlphaNumericInput();

	static void Flush();

	// Check if an input value is within a certain ascii boundary
	static bool WithinBounds(int val, int min, int max);

	static sf::Uint32 lastInput;
	static std::string inputBuffer;
private:
} s_ioHandler;

