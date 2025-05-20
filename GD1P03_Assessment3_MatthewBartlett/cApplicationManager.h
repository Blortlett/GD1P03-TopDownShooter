#pragma once
#include "cGameManager.h"

class cApplicationManager
{
private:
	sf::RenderWindow mGameWindow;
	cGameManager mGameManager;

public:
	cApplicationManager();
	~cApplicationManager();

	void Run();
};