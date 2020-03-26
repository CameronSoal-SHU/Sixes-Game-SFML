#pragma once
#include <string>

class Player
{
public:
	Player();
	~Player();

	unsigned GetPlayerBalance() const;
	void SetPlayerBalance(unsigned newBalance);

	unsigned GetRollsRemaining() const;
	void SetRollsRemaining(unsigned newRolls);
private:
	unsigned m_playerBalance;
	unsigned m_rollsRemaining;
};