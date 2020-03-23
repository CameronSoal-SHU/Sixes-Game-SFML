#pragma once
#include "MainGame.h"

class Application
{
public:
	Application();
	//~Application();

	void Run();
private:
	MainGame m_mainGame;
	sf::RenderWindow m_renderWindow;
};

