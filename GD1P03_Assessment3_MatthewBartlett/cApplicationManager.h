#pragma once
#include "cGameManager.h"
#include "cMainMenu.h"



class cApplicationManager
{
private:
	sf::RenderWindow mGameWindow;
	cGameManager mGameManager;

	cMainMenu mMainMenu;
	sf::View mDefaultView;
public:
	cApplicationManager();
	~cApplicationManager();

	void Run();
};