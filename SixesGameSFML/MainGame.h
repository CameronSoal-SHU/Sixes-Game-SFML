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
	Dice m_die = Dice(3.f);

	void RenderMessage(const std::string& msg);

	// Menus to render
	void RenderMainMenu();
	void RenderBettingScreen();
	void RenderDiceRolling();
	void RenderReturnToBettingScreen();
	void RenderDiceResult();
	void RenderWinMenu();
	void RenderLossMenu();
};