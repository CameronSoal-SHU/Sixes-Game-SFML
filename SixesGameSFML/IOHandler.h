#pragma once
#include "SFML/Graphics.hpp"
#include <string>

/* 
Static class to handle receiving and validating inputs by the user
*/
class IOHandler
{
public:
	// Functions used to limit inputs
	static void NumericInput();
	static void AlphaInput();
	static void AlphaNumericInput();

	/* Used to clear both the lastInput and inputBuffer variables
	When the held data is no longer needed */
	static void Flush();

	/* Check if an input value is within a certain ascii boundary
	<param "val"> The value to be checked </param>
	<param "min"> The minimum bound </param>
	<param "max"> The maximum bound </param>
	<return> Returns true if val is within the given bounds </return>
	*/
	static bool WithinBounds(int val, int min, int max);

	// Hold the last known character inputted by the user
	static sf::Uint32 lastInput;
	// Hold cumulative input characters whenever necessary
	static std::string inputBuffer;
};
