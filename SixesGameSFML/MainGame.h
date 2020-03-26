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
	bool inputValid = true;
	Player m_player;
	Dice m_die = Dice(1.25f);

	void RenderMessage(const std::string& msg);
	void RenderPlayerStats();

	// Menus to render
	void RenderMainMenu();
	void RenderBettingScreen();

	// To be shown to immitate rolling dice
	void RenderDiceRolling();

	// Tell the player the result and whether they won or lost
	void RenderWinMenu();
	void RenderLossMenu();
};