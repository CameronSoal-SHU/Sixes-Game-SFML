#include "Player.h"



Player::Player()
	: m_playerBalance(0), m_rollsRemaining(0)
{}

int Player::GetPlayerBalance()
{
	return m_playerBalance;
}

void Player::SetPlayerBalance(int newBalance)
{
	m_playerBalance = newBalance;
	printf_s("Player balance set to: %d\n", m_playerBalance);
}

int Player::GetRollsRemaining()
{
	return m_rollsRemaining;
}

void Player::SetRollsRemaining(int newRolls)
{
	m_rollsRemaining = newRolls;
	printf_s("Player rolls remaining set to: %d\n", m_rollsRemaining);
}

Player::~Player()
{
}
