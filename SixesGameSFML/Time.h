#pragma once
#include "SFML/Graphics.hpp"

// Static class to hold internal time information,
// for example: delta time between frames
static class Time
{
public:
	static void ResetClock();
	static float GetDeltaTime();
private:
	static sf::Clock m_clock;
	static float m_deltaTime;
} s_time;

