#include "Dice.h"
#include "RandomNumberGenerator.h"
#include "Time.h"

Dice::Dice() 
	: m_dieRollDur(5.f), rollDurRemaining(5.f) {
}

Dice::Dice(float rollDelay)
	: m_dieRollDur(rollDelay), rollDurRemaining(rollDelay) {
}

unsigned Dice::RollDice() {
	m_dieResult = RandomNumberGenerator::GenerateRandomUnsigned(6);
	return m_dieResult;
}

unsigned Dice::GetResult() const {
	return m_dieResult;
}

void Dice::ResetRollDelay() {
	rollDurRemaining = m_dieRollDur;
}