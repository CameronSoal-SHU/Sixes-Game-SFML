#pragma once
#include "GameData.h"
#include "GameManager.h"
#include "Player.h"

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
	Player m_player;
	unsigned m_diceResult;
	GameManager m_gameManager;

	void RenderMainMenu();
	void RenderBettingScreen();
	void RenderReturnToBettingScreen();
	void RenderDiceResult();
	void RenderWinMenu();
	void RenderLossMenu();
};