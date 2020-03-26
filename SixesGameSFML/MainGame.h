#pragma once
#include "GameData.h"
#include "GameManager.h"
#include "Player.h"
#include "Dice.h"

class MainGame
{
public:
	MainGame();

	void Init(sf::RenderWindow& renWin);
	void Update();
	void Render();

	void TextEntered(sf::Uint32 input);

	static GameData gameData;
	static GameSettings gameSettings;
private:
	GameManager m_gameManager;
	Player m_player;
	Dice m_die = Dice(1.25f);

	bool inputValid = true;

	void RenderMessage(const std::string& msg);
	void RenderPlayerStats();

	// Menus to render (called in Render()) 
	// with corresponding logic handlers (to be called in Update() when necessary)
	void MainMenuLogic();
	void RenderMainMenu();

	void BettingScreenLogic();
	void RenderBettingScreen();

	// To be shown to immitate rolling dice
	void DiceRollingLogic();
	void RenderDiceRolling();

	// Tell the player the result and whether they won or lost
	void ResultsScreenLogic();
	void RenderWinScreen();
	void RenderLossScreen();
};