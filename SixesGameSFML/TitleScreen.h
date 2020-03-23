#pragma once
class GameManager;

class TitleScreen
{
public:
	void Init(GameManager* gameManagerPtr);
	TitleScreen();
	~TitleScreen();
private:
	GameManager* m_gameManagerPtr;
};

