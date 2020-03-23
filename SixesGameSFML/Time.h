#pragma once
#include "SFML/Graphics.hpp"

class Time
{
public:
	static void ResetClock();
	static float GetDeltaTime();
private:
	static sf::Clock m_clock;
	static float m_deltaTime;
};

