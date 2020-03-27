#pragma once
#include <string>

/*
Class to hold data about the players play session,
hold the players balance, how many rolls they have left, etc.
*/
class Player
{
public:
	/* Initialise the players balance and rolls to 0 */
	Player();

	/* Getters and Setters */
	unsigned GetPlayerBalance() const;
	void SetPlayerBalance(unsigned newBalance);

	unsigned GetRollsRemaining() const;
	void SetRollsRemaining(unsigned newRolls);
private:
	unsigned m_playerBalance;	// Players "pot"
	unsigned m_rollsRemaining;	// Players "bet"
};