#include "MainGame.h"
#include "IOHandler.h"
#include "Time.h"

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
		IOHandler::NumericInput();										// Only accept numeric inputs for pot amount

		if (IOHandler::lastInput == GameConstants::RETURN_KEY) {
			MainMenuLogic();
		}
		break;
	case GameManager::BETTING_MENU:
		IOHandler::NumericInput();

		if (IOHandler::lastInput == GameConstants::RETURN_KEY && m_player.GetPlayerBalance() != 0) {
			BettingScreenLogic();
		}
		break;
	case GameManager::ROLL_DICE:
		DiceRollingLogic();
		break;
	case GameManager::WIN:
	case GameManager::LOSS:
		ResultsScreenLogic();
		break;
	default:	// Should never be taken
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
		RenderBettingScreen();
		if (!inputValid) {	// Show an error message on invalid betting values
			std::string errorMessage = "\n\n\n\n\n\nInvalid betting amount!";
			RenderMessage(errorMessage);
		}
		break;
	case GameManager::ROLL_DICE:
		RenderDiceRolling();
		break;
	case GameManager::WIN:
		RenderWinMenu();
		break;
	case GameManager::LOSS:
		RenderLossMenu();
		break;
	default:	// Should never be taken
		assert(false);
		break;
	}
}

void MainGame::MainMenuLogic() {
	const unsigned potAmount = stoi(IOHandler::inputBuffer);

	if (inputValid = (potAmount > 0)) {							// Check if the pot amount is valid
		printf_s("Pot Amount Valid!\n");

		m_player.SetPlayerBalance(potAmount);					// If so, set the balance and rolls remaining
		m_player.SetRollsRemaining((int)floorf((float)potAmount / gameSettings.m_costPerDice));

		IOHandler::inputBuffer = "0";							// Reset input buffer for betting screen
		m_gameManager.OnStateChange(GameManager::BETTING_MENU);	// Change to betting screen
	}
	else {
		printf_s("Pot Amount Invalid!\n");
		IOHandler::inputBuffer = "0";
	}
}

void MainGame::RenderMainMenu() {
	std::string mainMenuText = "Welcome to sixes!\nPay: " + 
		std::to_string(gameSettings.m_costPerDice) + " Coin(s) per dice, throw a 6 to win: " + 
		std::to_string(gameSettings.m_rewardPayOut) + "\nEnter how many coins you want in the pot: " +
		IOHandler::inputBuffer + "\nEnter amount and press <Return> to continue..." + 
		"\nPress <ESC> to exit...";

	RenderMessage(mainMenuText);
}

void MainGame::BettingScreenLogic() {
	const unsigned bettingAmount = stoi(IOHandler::inputBuffer);

	if (inputValid = (bettingAmount > 0 &&						// Is the input valid and affordable?
		bettingAmount <= (unsigned)(m_player.GetPlayerBalance() / gameSettings.m_costPerDice))) {
		printf_s("Betting Amount Valid!\n");

		m_player.SetRollsRemaining(bettingAmount - 1);			// Set player die rolls and subtract cost from player balance
		m_player.SetPlayerBalance(m_player.GetPlayerBalance() - (bettingAmount * gameSettings.m_costPerDice));

		m_gameManager.OnStateChange(GameManager::ROLL_DICE);	// "Roll" the dice!
	}
	else {
		printf_s("Betting Amount Invalid!\n");
		IOHandler::inputBuffer = "0";
	}
}

void MainGame::RenderBettingScreen() {
	std::string bettingMenuText = "Sixes\nHow much do you want to bet? (" + std::to_string(gameSettings.m_costPerDice) +
		" Coin(s) per die roll)\nYour pot stands at: " + std::to_string(m_player.GetPlayerBalance()) +
		"\nBetting Amount: " + IOHandler::inputBuffer +
		"\nPress <ESC> to cash out";

	if (m_player.GetPlayerBalance() != 0) {
		bettingMenuText += "\nEnter an amount and press <Return> to continue...";
	}
	else {
		bettingMenuText += "\nOut of coins!";
	}

	RenderMessage(bettingMenuText);
}

void MainGame::DiceRollingLogic() {
	if (m_die.rollDurRemaining > 0.f) {	// Simulate duration of rolling a dice
		m_die.rollDurRemaining -= Time::GetDeltaTime();
	}
	else {
		m_die.ResetRollDelay();
		if (m_die.RollDice() == 6) {	// Player won! - add coins to balance!
			m_player.SetPlayerBalance(m_player.GetPlayerBalance() + gameSettings.m_rewardPayOut);
			m_gameManager.OnStateChange(GameManager::WIN);
		}								// Player lost! - nothing added
		else m_gameManager.OnStateChange(GameManager::LOSS);
	}
}

void MainGame::RenderDiceRolling() {
	std::string diceRollingText = "Sixes\nRolling Dice...\nTime Remaining: " + 
		std::to_string(m_die.rollDurRemaining);

	RenderMessage(diceRollingText);
}

void MainGame::ResultsScreenLogic()
{
	if (IOHandler::lastInput == GameConstants::RETURN_KEY) {		// Return player back to betting menu
		if (m_player.GetRollsRemaining() == 0) {					// when there are no more rolls left
			m_gameManager.OnStateChange(GameManager::BETTING_MENU);
		}
		else {														// Otherwise, deduct a roll and go again
			m_player.SetRollsRemaining(m_player.GetRollsRemaining() - 1);
			m_gameManager.OnStateChange(GameManager::ROLL_DICE);
		}
	}
}

void MainGame::RenderWinMenu() {
	std::string winMenuText = "\n\n\n\nYou won! " + 
		std::to_string(gameSettings.m_rewardPayOut) +
		" Coin(s) added to pot";

	if (m_player.GetRollsRemaining() > 0) {
		winMenuText += "\nPress <Return> to roll again!";
	}
	else {
		winMenuText += "\nOut of Rolls! - Press <Return> to return to betting menu!";
	}

	RenderPlayerStats();
	RenderMessage(winMenuText);
}

void MainGame::RenderLossMenu() {
	std::string lossMenuText = "\n\n\n\nYou lost! Better luck next time!";

	if (m_player.GetRollsRemaining() > 0) {
		lossMenuText += "\nPress <Return> to roll again!";
	}
	else {
		lossMenuText += "\nOut of Rolls! - Press <Return> to return to betting menu!";
	}

	RenderPlayerStats();
	RenderMessage(lossMenuText);
}

void MainGame::RenderMessage(const std::string& msg) {
	sf::Text message = sf::Text(msg, gameData.m_font);

	gameData.m_renderWindow->draw(message);
}

void MainGame::RenderPlayerStats() {
	std::string playerStatsText = "Sixes\nDie Result: " + std::to_string(m_die.GetResult()) +
		"\nRolls Remaining: " + std::to_string(m_player.GetRollsRemaining()) +
		"\nPot: " + std::to_string(m_player.GetPlayerBalance());

	RenderMessage(playerStatsText);
}