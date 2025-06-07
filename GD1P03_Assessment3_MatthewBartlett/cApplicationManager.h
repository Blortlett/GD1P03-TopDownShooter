#pragma once
#include "cGameManager.h"
#include "cMainMenu.h"

class cApplicationManager
{
private:
	enum class EGameState
	{
		MainMenu,
		Gameplay
	};

	sf::RenderWindow mGameWindow;
	cGameManager mGameManager;

	cMainMenu mMainMenu;
	EGameState mCurrentState;
public:
	cApplicationManager();
	~cApplicationManager();

	void Run();
};