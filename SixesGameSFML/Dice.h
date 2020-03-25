#pragma once
class Dice
{
public:
	Dice();
	Dice(float rollDelay);

	unsigned RollDice();
	unsigned GetResult() const;

	void ResetRollDelay();
	float rollDurRemaining;
private:
	unsigned m_dieResult;
	float m_dieRollDur;
};

