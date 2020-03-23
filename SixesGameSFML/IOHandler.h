#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class IOHandler
{
public:
	static void NumericInput();
	static void AlphaInput();
	static void AlphaNumericInput();
	static void Flush();
	static bool WithinBounds(float val, float min, float max);

	static sf::Uint32 lastInput;
	static std::string inputBuffer;
private:
};

