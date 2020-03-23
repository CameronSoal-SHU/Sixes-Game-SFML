#pragma once
#include <string>
#include <sstream>

class Player
{
public:
	Player();
	~Player();

	int GetPlayerBalance();
	void SetPlayerBalance(int newBalance);

	int GetRollsRemaining();
	void SetRollsRemaining(int newRolls);
private:
	int m_playerBalance;
	int m_rollsRemaining;
};