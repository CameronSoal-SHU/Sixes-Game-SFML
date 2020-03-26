#include "Player.h"


Player::Player()
	: m_playerBalance(0), m_rollsRemaining(0)
{}

unsigned Player::GetPlayerBalance() const
{
	return m_playerBalance;
}

void Player::SetPlayerBalance(unsigned newBalance)
{
	m_playerBalance = newBalance;
	printf_s("Player balance set to: %d\n", m_playerBalance);
}

unsigned Player::GetRollsRemaining() const
{
	return m_rollsRemaining;
}

void Player::SetRollsRemaining(unsigned newRolls)
{
	m_rollsRemaining = newRolls;
	printf_s("Player rolls remaining set to: %d\n", m_rollsRemaining);
}

Player::~Player()
{
}
