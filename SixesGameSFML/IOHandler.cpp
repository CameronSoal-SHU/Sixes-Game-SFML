#include "IOHandler.h"
#include "GameData.h"

sf::Uint32 IOHandler::lastInput;
std::string IOHandler::inputBuffer;

bool IOHandler::WithinBounds(float val, float min, float max)
{
	return !(val < min || val > max); // Make sure value is within boundaries
}

void IOHandler::AlphaNumericInput()
{}

void IOHandler::AlphaInput()
{}

void IOHandler::NumericInput()
{
	if (lastInput == GameConstants::BACKSPACE)
	{
		if (inputBuffer.length() > 1)
			inputBuffer.erase(inputBuffer.end() - 1);	// Remove last character
		else
			inputBuffer = "0";							// Always make an empty numeric input buffer default to 0
	}
	// Only take numbers 0-9
	else if (!(lastInput < GameConstants::NUM_MIN || lastInput > GameConstants::NUM_MAX))
	{
		// Check if the default needs to be replaced
		if (inputBuffer == "0")
			inputBuffer = lastInput;						// Remove proceeding 0
		else
			inputBuffer += static_cast<char>(lastInput);	// Add number onto the end
	}
}

// Reset the buffer and last input
void IOHandler::Flush()
{
	inputBuffer = "";
	lastInput = NULL;
}