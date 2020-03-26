#pragma once
#include "SFML/Graphics.hpp"

namespace GameConstants
{
	const int SCREEN_RES_X{ 1200 };
	const int SCREEN_RES_Y{ 900 };

	const char ESCAPE_KEY{ 27 };
	const char RETURN_KEY{ 13 };
	const char BACKSPACE{ 8 };

	// All ascii
	const char ASCII_LIMIT{ 127 };

	// Upper-case
	const char ALPHA_UC_MIN{ 65 };
	const char ALPHA_UC_MAX{ 90 };

	// Lower-case
	const char ALPHA_LC_MIN{ 97 };
	const char ALPHA_LC_MAX{ 122 };

	// Numbers 0-9
	const char NUM_MIN{ 48 };
	const char NUM_MAX{ 57 };
}

struct GameData
{
	sf::RenderWindow* m_renderWindow;
	sf::Font m_font;
};

struct GameSettings
{
	int m_costPerDice{ 1 };
	int m_rewardPayOut{ 10 };
};