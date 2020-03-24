#include "MainGame.h"
#include "IOHandler.h"

#include <assert.h>

// Forward declaration(s)
GameManager::game_state GameManager::gameState;
GameData MainGame::gameData;
GameSettings MainGame::gameSettings;

MainGame::MainGame()
{}

void MainGame::Init(sf::RenderWindow & renWin) {
	gameData.m_renderWindow = &renWin;
	assert(gameData.m_font.loadFromFile("../Assets/Fonts/DroidSans.ttf"));

	m_gameManager.Init(this);
	IOHandler::inputBuffer = "0";	// Setup input buffer for pot amount input
}

void MainGame::TextEntered(sf::Uint32 input) {
	if (input == GameConstants::ESCAPE_KEY)
		gameData.m_renderWindow->close();
	else IOHandler::lastInput = input;
}

void MainGame::Update() {
	switch (m_gameManager.gameState) {
	case GameManager::INIT:
		break;
	case GameManager::MAIN_MENU:
		IOHandler::NumericInput();						// Only accept numeric inputs for pot amount

		if (IOHandler::lastInput == GameConstants::RETURN_KEY) {
			unsigned potAmount = stoi(IOHandler::inputBuffer);

			if (inputValid = (potAmount > 0)) {						// Check if the pot amount is valid
				printf_s("Pot Amount Valid!\n");
				m_player.SetPlayerBalance(potAmount);				// If so, set the balance and rolls remaining
				m_player.SetRollsRemaining((int)floorf((float)potAmount / gameSettings.m_costPerDice));
			}
			else {
				printf_s("Pot Amount Invalid!\n");
			}
		}
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
		assert(false);
		break;
	}

	// Clear last input
	IOHandler::lastInput = NULL;
}

void MainGame::Render() {
	switch (m_gameManager.gameState) {
	case GameManager::INIT:
		break;
	case GameManager::MAIN_MENU:
		RenderMainMenu();
		if (!inputValid) {	// Show an error message on invalid pot values
			std::string errorMessage = "\n\n\n\n\nInvalid pot amount!";
			RenderMessage(errorMessage);
		}
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
		assert(false);
		break;
	}
}

void MainGame::RenderMainMenu() {
	std::string textToRender = "Welcome to sixes!\nPay: " + 
		std::to_string(gameSettings.m_costPerDice) + " Coin(s) per dice, throw a 6 to win: " + std::to_string(gameSettings.m_rewardPayOut) + 
		"\nEnter how many coins you want in the pot: " + IOHandler::inputBuffer + "\nEnter amount and press <Return> to continue..." + 
		"\nPress <ESC> to exit...";

	sf::Text mainMenuText = sf::Text(textToRender, gameData.m_font);

	gameData.m_renderWindow->draw(mainMenuText);
}

void MainGame::RenderMessage(const std::string& msg) {
	sf::Text message = sf::Text(msg, gameData.m_font);

	gameData.m_renderWindow->draw(message);
}