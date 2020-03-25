#include "GameManager.h"

// Forward declaration(s)
GameManager::game_state m_gameState;

GameManager::GameManager()
	: m_mainGamePtr(nullptr)
{
	OnStateChange(INIT);
	printf_s("Game Initialised!\n");
}

void GameManager::Init(MainGame* mainGamePtr)
{
	m_mainGamePtr = mainGamePtr;
	OnStateChange(MAIN_MENU);
}

void GameManager::OnStateChange(GameManager::game_state newState)
{
	if (gameState != newState)
	{
		printf_s("State changed to: ");
		switch (newState)
		{
		case INIT:
			printf_s("Init!\n");
			break;
		case MAIN_MENU:
			printf_s("Main Menu!\n");
			break;
		case BETTING_MENU:
			printf_s("Betting Menu!\n");
			break;
		case ROLL_DICE:
			printf_s("Roll Dice!\n");
			break;
		case WIN:
			printf_s("Win!\n");
			break;
		case LOSS:
			printf_s("Loss!\n");
			break;
		default:
			printf_s("UNKNOWN!\n");
			break;
		}

		gameState = newState;
	}
}