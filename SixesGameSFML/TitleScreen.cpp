#include "TitleScreen.h"


TitleScreen::TitleScreen()
	: m_gameManagerPtr(nullptr)
{}

void TitleScreen::Init(GameManager* gameManagerPtr)
{
	m_gameManagerPtr = gameManagerPtr;
}


TitleScreen::~TitleScreen()
{
}
