#pragma once
#include <string>

class MainGame;

class GameManager
{
public:
	// Possible game states
	enum game_state
	{
		INIT,
		MAIN_MENU,
		BETTING_MENU,
		ROLL_DICE,
		WIN,
		LOSS
	};

	GameManager();
	//~GameManager();

	void Init(MainGame* mainGamePtr);
	void Update() {};

	static game_state gameState;
	void OnStateChange(game_state newState);
private:
	MainGame* m_mainGamePtr;
};

