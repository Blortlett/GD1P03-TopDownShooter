#pragma once
#include <SFML/Graphics.hpp>
#include "cAmmoUI.h"
#include "cPauseMenu.h"
#include "cOptionsMenuUI.h"
#include "cDebugMenuUI.h"

class cPlayerCharacter;

class cViewUI
{
private:
	sf::View mUICanvas;
	cAmmoUI mAmmoUI;
	cPauseMenu mPauseMenuUI;
	cOptionsMenuUI mOptionsMenuUI;
	cDebugMenuUI mDebugMenuUI;

	sf::RenderWindow& mGameWindow;
	cPlayerCharacter& mPlayerCharacter;

public:
	cViewUI(sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter);

	void Update();
	void Draw();
};