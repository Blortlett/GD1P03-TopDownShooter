#pragma once
#include <SFML/Graphics.hpp>
#include "cAmmoUI.h"
#include "cPauseMenu.h"
#include "cOptionsMenuUI.h"
#include "cDebugMenuUI.h"
#include "cLevelCompleteUI.h"

class cPlayerCharacter;

class cViewUI
{
private:
	sf::View mUICanvas;
	// UI Elements
	cAmmoUI mAmmoUI;
	cPauseMenu mPauseMenuUI;
	cOptionsMenuUI mOptionsMenuUI;
	cDebugMenuUI mDebugMenuUI;
	cLevelCompleteUI mLevelCompleteUI;

	// Game Components
	sf::RenderWindow& mGameWindow;
	cPlayerCharacter& mPlayerCharacter;
	cGameStateManager& mGameStateManager;

public:
	cViewUI(sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter, cGameStateManager& _GameStateManager);

	void Update(float _DeltaTime);
	void Draw();
};