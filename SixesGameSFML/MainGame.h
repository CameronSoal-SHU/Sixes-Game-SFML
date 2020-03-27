#pragma once
#include "GameData.h"
#include "GameManager.h"
#include "Player.h"
#include "Dice.h"

/* 
Main class to initialise, update and render the game.
Handles the data and inputs and what should be displayed on the screen
through communication with other classes (such as Player, IOHandler, GameManager, etc.)
*/
class MainGame
{
public:
	/* 
	Sets up render window reference, font, GameManager and IOHandler
	<param "renWin">RenderWindow reference to be stored in GameData</param>
	*/
	MainGame(sf::RenderWindow& renWin);

	/* Called every frame to handle inputs and data */
	void Update();
	/* Called after update to render on screen information */
	void Render();

	/* 
	Retrieves and stores inputs from Application 
	<param "input"> Recieved input from Application </param>
	*/
	void TextEntered(sf::Uint32 input);

	/* Holds references to game data to be used across the program */
	static GameData gameData;
	/* Holds game settings to be used by the game, e.g. payout amounts */
	static GameSettings gameSettings;
private:
	Player m_player;
	/* Dice with 1.25 second roll time */
	Dice m_die = Dice(1.25f);

	/* Valid input flag */
	bool inputValid = true;

	/* 
	Creates and draws a given text message on screen
	<param "msg"> Message to render </param>
	*/
	void RenderMessage(const std::string& msg);
	/*
	Display players statistical data on screen,
	such as the player score, remaining balance, etc.
	*/
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