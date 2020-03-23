#include "MainGame.h"
#include "IOHandler.h"

#include <assert.h>


void MainGame::Init(sf::RenderWindow & renWin) {
	gameData.m_renderWindow = &renWin;
	assert(gameData.m_font.loadFromFile("../Assets/Fonts/DroidSans.ttf"));

	m_gameManager.Init(this);
}

void MainGame::TextEntered(sf::Uint32 input) {
	if (input == GameConstants::ESCAPE_KEY)
		gameData.m_renderWindow->close();
}

void MainGame::Update() {
	switch (m_gameManager.gameState)
	{
	case GameManager::INIT:
		break;
	case GameManager::MAIN_MENU:
		break;
	case GameManager::BETTING_MENU:
		break;
	case GameManager::ROLL_DICE:
		break;
	case GameManager::WIN:
		break;
	case GameManager::LOSS:
		break;
	default:
		break;
	}
}

void MainGame::Render() {
	switch (m_gameManager.gameState)
	{
	case GameManager::INIT:
		break;
	case GameManager::MAIN_MENU:
		break;
	case GameManager::BETTING_MENU:
		break;
	case GameManager::ROLL_DICE:
		break;
	case GameManager::WIN:
		break;
	case GameManager::LOSS:
		break;
	default:
		break;
	}
}